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
    }
    readFile();
    hashInsert();
    sortWords();
    printf("Total number of indexed words: %d\n", totalIndexedWords);
    printf("Total number of comparison: %d\n", compare);
}

int hash(char* word) {
    int sum = 0;
    int i = 0;
    unsigned int poly = 0xEDB88320;
    while (*word) {
        poly = (poly << 1) | (poly >> (32-1));
        sum = (int)(poly * sum + *word++);
        compare++;
        i++;
    }
    for(i; i <8;i++) {
        poly = (poly << 1) | (poly >> (32-1));
        sum = (int)(poly * sum + 46);
    }

    return sum % HASH_TABLE_SIZE > 0? sum % HASH_TABLE_SIZE: -1 * sum % HASH_TABLE_SIZE;
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
                int hashValue = hash(token);
                //doc num
                int tmpDocNum = i;
                //line num
                int tmpLineNum = j;
                 //word data
                hashTable[hashValue][tmpDocNum]->cnt++;
                queue_node_pointer tmp = (queue_node_pointer) malloc(sizeof(queue_node));
                tmp->line = tmpLineNum;
                tmp->link = NULL;
                enQueue(hashTable[hashValue][tmpDocNum]->lines, tmp);

                hashTable[hashValue][0]->cnt++;
                strcpy(hashTable[hashValue][0]->word, token);
                enQueueDoc(hashTable[hashValue][0]->lines, tmpDocNum);

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
    printf("\n------------ Result ------------\n");
    printf("Keyword: %s\n", oneWord);
    printf("Total number of documents: %d\n", hashTable[hashValue][0]->cnt);
    bst_show(hashTable[hashValue][0]->bst);
    printf("\nTotal number of comparison: %d\n", compare);
}