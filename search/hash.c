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

char* split(char* line) {
    while (line != NULL) {
        char* word = strtok(line, " \t\n");
        while (word != NULL) {
            // special char X
            int i, j;
            for (i = 0, j = 0; word[i] != '\0'; i++) {
                if (isalpha(word[i])) {
                    word[j++] = tolower(word[i]);
                }
            }
            word[j] = '\0';
            word = strtok(NULL, " \t\n");
        }
        return word; 
    }
}

void hashInsert() {
    int i, j, k;
    for(i = 0; i < 101; i++) {
        while(fileData[i][j][k] != '\0') {
            while(fileData[i][j][k] != '\0') {
                //hashing
                int hashValue = hash(split(&fileData[i][j][k]));
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
                k++;
            }
            j++;
        }
    }
}

void search(){
    scanf("%s", searchTarget);

    int hashValue = hash(searchTarget);
    printf("------------ Result ------------\n");
    printf("Keyword: %s\n", searchTarget);
    printf("Total documents: %d", hashTable[hashValue][0]->cnt);
    bst_show(hashTable[hashValue][0]->bst);
}