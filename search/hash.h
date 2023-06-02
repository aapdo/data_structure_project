#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define TABLE_SIZE 100

typedef struct FileNode {
    char fileName[MAX_WORD_LENGTH];
    int lineNumber;
    struct FileNode* next;
} FileNode;

typedef struct wordData* word_pointer;
typedef struct tree_pointer tree_pointer;

typedef struct tree_node {
    word_pointer data;
    tree_pointer left;
    tree_pointer right;
} tree_node;

typedef struct wordData {
    char key[MAX_WORD_LENGTH];
    int count;
    FileNode* fileList;
    tree_pointer tree_node;
    struct wordData* next;
} wordData;

wordData* hashTable[TABLE_SIZE] = { NULL };

unsigned int hash(const char* key) {
    unsigned int hashVal = 0;
    int i = 0;

    while (key[i] != '\0') {
        hashVal = (hashVal << 5) + key[i];
        i++;
    }

    return hashVal % TABLE_SIZE;
}

int compareIgnoreCase(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (tolower(*str1) != tolower(*str2)) {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}

void insertOrUpdate(const char* key, const char* fileName, int lineNumber) {
    unsigned int index = hash(key);
    wordData* current = hashTable[index];

    while (current != NULL) {
        if (compareIgnoreCase(current->key, key)) {
            current->count++;

            FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
            if (newNode == NULL) {
                printf("메모리 할당에 실패했습니다.\n");
                return;
            }
            strcpy(newNode->fileName, fileName);
            newNode->lineNumber = lineNumber;
            newNode->next = current->fileList;
            current->fileList = newNode;

            return;
        }
        current = current->next;
    }

    wordData* newwordData = (wordData*)malloc(sizeof(wordData));
    if (newwordData == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        return;
    }

    strcpy(newwordData->key, key);
    newwordData->count = 1;
    newwordData->next = NULL;

    FileNode* newNode = (FileNode*)malloc(sizeof(FileNode));
    if (newNode == NULL) {
        printf("메모리 할당에 실패했습니다.\n");
        free(newwordData);
        return;
    }
    strcpy(newNode->fileName, fileName);
    newNode->lineNumber = lineNumber;
    newNode->next = NULL;

    newwordData->fileList = newNode;

    if (hashTable[index] == NULL) {
        hashTable[index] = newwordData;
    }
    else {
        wordData* current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newwordData;
    }
}

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


int main() {
    char fileName[15];
    char searchWord[MAX_WORD_LENGTH];

    for (int i = 1; i <= 100; i++) {
        sprintf(fileName, "doc%03d.txt", i);
        processFile(fileName);
    }

    printf("검색할 단어를 입력하세요: ");
    scanf("%s", searchWord);

    SearchWord(searchWord);

    return 0;
}
