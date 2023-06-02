#include "../data.h"
#include "../utils.h"
#include "../reader/reader.h"

// typedef struct FileNode {
//     char fileName[MAX_WORD_LENGTH];
//     int lineNumber;
//     struct FileNode* next;
// } FileNode;

// typedef struct wordData* word_pointer;
// typedef struct tree_pointer tree_pointer;

// typedef struct tree_node {
//     word_pointer data;
//     tree_pointer left;
//     tree_pointer right;
// } tree_node;

// typedef struct wordData {
//     char key[MAX_WORD_LENGTH];
//     int count;
//     FileNode* fileList;
//     tree_pointer tree_node;
//     struct wordData* next;
// } wordData;

//hash init
void hashInit();
//hash
int hash(char* word);
//hashing and insert data
void hashInsert();
void sortWords();

void buildTree(wordData* wordData) {
    FileNode* fileNode = wordData->fileList;

    while (fileNode != NULL) {
        tree_pointer newNode = (tree_pointer)malloc(sizeof(tree_node));
        if (newNode == NULL) {
            printf("메모리 할당에 실패했습니다.\n");
            return;
        }
        newNode->value = wordData->count;
        newNode->left = NULL;
        newNode->right = NULL;

        if (wordData->tree_node == NULL) {
            wordData->tree_node = newNode;
        }
        else {
            tree_pointer current = wordData->tree_node;
            while (1) {
                if (wordData->count <= current->value) {
                    if (current->left == NULL) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if (current->right == NULL) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }

        fileNode = fileNode->next;
    }
}

void printTreeInOrder(tree_pointer tree_node, const char* key) {
    if (tree_node == NULL) {
        return;
    }

    printTreeInOrder(tree_node->right, key);

    wordData* wordData = hashTable[hash(key)];
    FileNode* fileNode = wordData->fileList;
    while (fileNode != NULL) {
        if (fileNode->lineNumber == tree_node->value) {
            printf("- 파일명: %s, 줄 번호: %d\n", fileNode->fileName, fileNode->lineNumber);
            break;
        }
        fileNode = fileNode->next;
    }

    printTreeInOrder(tree_node->left, key);
}

void SearchWord(const char* key) {
    unsigned int index = hash(key);
    wordData* current = hashTable[index];

    while (current != NULL) {
        if (strcasecmp(current->key, key) == 0) {
            printf("단어: %s\n", current->key);
            printf("총 출현 횟수: %d\n", current->count);
            printf("출현 위치:\n");

            FileNode* fileNode = current->fileList;
            int fileCount = 0;
            while (fileNode != NULL) {
                printf("- 파일명: %s, 줄 번호: %d\n", fileNode->fileName, fileNode->lineNumber);
                fileNode = fileNode->next;
                fileCount++;
            }

            printf("총 출현 파일 수: %d\n", fileCount);

            return;
        }
        current = current->next;
    }

    printf("단어를 찾을 수 없습니다.\n");
}


void processFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    char line[MAX_WORD_LENGTH];
    int lineNumber = 1;

    while (fgets(line, sizeof(line), file) != NULL) {
        char* word = strtok(line, " \t\n");
        while (word != NULL) {
            // 단어에서 특수문자 제거
            int i, j;
            for (i = 0, j = 0; word[i] != '\0'; i++) {
                if (isalpha(word[i])) {
                    word[j++] = tolower(word[i]);
                }
            }
            word[j] = '\0';

            if (strlen(word) > 0) {
                insertOrUpdate(word, fileName, lineNumber);
            }

            word = strtok(NULL, " \t\n");
        }
        lineNumber++;
    }

    fclose(file);
}
