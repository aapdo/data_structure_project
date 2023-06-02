#include "hash.h"

//call start of main
void hashInit() {
    for (int i = 0; i < hashSize; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            hashTable[i][j] = (word_pointer) malloc(sizeof(wordData));
            hashTable[i][j]->cnt = 0;
        }
    }
    readFile();
    hashInsert();
}

int hash(char* word) {
    int hashVal = 0;
    int i = 0;

    while (word[i] != '\0') {
        hashVal = (hashVal << 5) + word[i];
        compare++;
        i++;
    }

    return (hashVal % hashSize);
}

void hashInsert() {
    int i = 0;
    int j = 0;
    int k = 0;

    for(i = 0; i < 101; i++) {
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
                int tmpDocNum = i;
                //line num
                int tmpLineNum = j;
                 //word data
                hashTable[hashValue][tmpDocNum]->cnt++;
                queue_node_pointer tmp = (queue_node_pointer) malloc(sizeof(queue_node));
                tmp->line = tmpLineNum;
                enQueue(hashTable[hashValue][tmpDocNum]->lines, tmp);
                hashTable[hashValue][0]->cnt++;
                token = strtok(NULL, " "); // 다음 단어 추출
            }

            j++;
        }
    }
}

void search(){
    memset(oneWord, '\0', sizeof(oneWord));
    scanf("%s", oneWord);

    int hashValue = hash(oneWord);
    printf("------------ Result ------------\n");
    printf("Keyword: %s\n", oneWord);
    printf("Total documents: %d", hashTable[hashValue][0]->cnt);
    bst_show(hashTable[hashValue][0]->bst);
}