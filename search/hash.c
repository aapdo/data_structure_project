#include "hash.h"

//call start of main
void hashInit() {
    int j;
    for (int i = 0; i < hashSize; i++)
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
        }
    }
    readFile();
    hashInsert();
    //sortWords();
}

int hash(char* word) {
    int sum = 0;
    unsigned int poly = 0xEDB88320;
    while (*word) {
        poly = (poly << 1) | (poly >> (32-1));
        sum = (int)(poly * sum + *word++);
    }

    return sum % hashSize > 0? sum % hashSize: -1 * sum % hashSize;
}

void hashInsert() {
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 1; i < 101; i++) {
        j = 0;
        while(fileData[i][j][k] != '\0') {
            char* line = fileData[i][j];
            //remove empty space, tab, enter
            char* token = strtok(line, " \t\n");
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
                int tmpDocNum = i+1;
                //line num
                int tmpLineNum = j;
                 //word data
                hashTable[hashValue][tmpDocNum]->cnt++;
                queue_node_pointer tmp = (queue_node_pointer) malloc(sizeof(queue_node));
                tmp->line = tmpLineNum;
                enQueue(hashTable[hashValue][tmpDocNum]->lines, tmp);

                hashTable[hashValue][0]->cnt++;
                enQueueDoc(hashTable[hashValue][0]->lines, tmpDocNum);

                token = strtok(NULL, " \t\n");
            }
            j++;
        }
    }
}

void search(){
    fflush(stdin);
    memset(oneWord, '\0', sizeof(oneWord));
    printf("enter the word: ");
    scanf("%s", oneWord);

    int hashValue = hash(oneWord);
    printf("------------ Result ------------\n");
    printf("Keyword: %s\n", oneWord);
    printf("Total documents: %d\n", hashTable[hashValue][0]->cnt);
    bst_show(hashTable[hashValue][0]->bst);
}