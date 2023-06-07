#include "hash.h"

//call start of main
void hashInit() {
    int j;
    for (int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        for (j = 0; j < 101; j++)
        {
            //initialize
            hashTable[i][j] = (word_pointer) malloc(sizeof(wordData));
            hashTable[i][j]->cnt = 0;
            hashTable[i][j]->docNumber = j;
            hashTable[i][j]->lines = (queue_pointer) malloc(sizeof(queue));
            hashTable[i][j]->lines->front = NULL;
            hashTable[i][j]->lines->rear = NULL;
            hashTable[i][j]->bst = NULL;
            hashTable[i][j]->word = NULL;
        }
        hashTable[i][0]->word = (char*) malloc(sizeof(MAX_WORD_LEN));
        strcpy(hashTable[i][0]->word, "");
    }
    readFile();
    hashInsert();
    sortWords();
    printf("Total number of indexed words: %d\n", totalIndexedWords);
    printf("Total number of comparison: %d\n", compare);
}

int hash(char* word) {
    int sum = 0;
    unsigned int poly = 0xEDB88320;
    while (*word) {
        poly = (poly << 1) | (poly >> (32-1));
        sum = (int)(poly * sum + *word++);
        compare++;
    }
    compare++;
    return sum % HASH_TABLE_SIZE > 0? sum % HASH_TABLE_SIZE: -1 * sum % HASH_TABLE_SIZE;
}

int linearInsert(char* word) {
    unsigned int index = hash(word);

    if (strlen(hashTable[index][0]->word) > 0) {
        if (strcmp(hashTable[index][0]->word, word) == 0 && hashTable[index][0]->cnt > 0) {
            // 동일한 키 값이 이미 존재하며, 단어도 같은 경우 충돌이 아님
            return index;
        }

        // 충돌 해결을 위한 선형 탐사
        unsigned int nextIndex = (index + 1) % HASH_TABLE_SIZE;
        while (nextIndex != index && strlen(hashTable[nextIndex][0]->word) > 0) {
            if (strcmp(hashTable[nextIndex][0]->word, word) == 0 && hashTable[nextIndex][0]->word == word) {
                // 동일한 키 값이 이미 존재하며, 단어도 같은 경우 충돌이 아님
                return nextIndex;
            }
            nextIndex = (nextIndex + 1) % HASH_TABLE_SIZE;
        }

        // 빈 슬롯을 찾아 값을 삽입
        if (strlen(hashTable[nextIndex][0]->word) == 0) {
            index = nextIndex;
        } else {
            // 해시 테이블이 가득 찬 경우
            fprintf(stderr, "Error: Hash table is full\n");
            return -1;
        }
    }

    // 새로운 키와 값을 삽입
    return index;
}

void hashInsert() {
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 1; i < 101; i++) {
        j = 0;
        while(fileData[i][j][k] != '\0') {
            //char* line = fileData[i][j];
            strcpy(oneLine, fileData[i][j]);
            //remove empty space, tab, enter
            char* token = strtok(oneLine, " \t\n");
            while (token != NULL) {
                //remove special char
                int l, m;
                for (l = 0, m = 0; token[l] != '\0'; l++) {
                    if (isalpha(token[l])) {
                        token[m++] = tolower(token[l]);
                    }
                }
                token[m] = '\0';

                //hashing
//                int hashValue = hash(token);
                int index = linearInsert(token);
                //doc num
                int tmpDocNum = i;
                //line num
                int tmpLineNum = j;

//                while (strcmp(hashTable[index][0]->word, "") != 0 && strcmp(hashTable[index][0]->word, token) != 0) {
//                    index = (index +1) % HASH_TABLE_SIZE;
//
//                    if(index == hashValue) {
//                        printf("Full\n");
//                        return;
//                    }
//                }

                //word data
                hashTable[index][tmpDocNum]->cnt++;
                queue_node_pointer tmp = (queue_node_pointer) malloc(sizeof(queue_node));
                tmp->line = tmpLineNum;
                tmp->link = NULL;
                enQueue(hashTable[index][tmpDocNum]->lines, tmp);

                hashTable[index][0]->cnt++;
                strcpy(hashTable[index][0]->word, token);
                enQueueDoc(hashTable[index][0]->lines, tmpDocNum);

                token = strtok(NULL, " \t\n");
            }
            j++;
        }
    }
}

void search(){
    fflush(stdin);
    compare = 0;
    memset(oneWord, '\0', sizeof(oneWord));
    printf("enter the word: ");
    scanf("%s", oneWord);

    int hashValue = hash(oneWord);
    int index = hashValue;

    while (strcmp(hashTable[index][0]->word, "") != 0) {
        if (strcmp(hashTable[index][0]->word, oneWord) == 0) {
            break;
        }
        index = (index + 1) % HASH_TABLE_SIZE;

        if (index == hashValue) {
            printf("NO\n");
            return;
        }
    }

    printf("\n------------ Result ------------\n");
    printf("Keyword: %s\n", oneWord);
    printf("Total number of documents: %d\n", hashTable[index][0]->cnt);
    bst_show(hashTable[index][0]->bst);
    printf("\nTotal number of comparison: %d\n", compare);
}