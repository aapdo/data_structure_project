#include "hash.h"

//call start of main
void hashInit(){
    for (int i = 0; i < hashSize; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            hashTable[i][j] = (word_pointer) malloc(sizeof(wordData));
            hashTable[i][j]->cnt = 0;
        }
    }
}

int hash(char* fileData) {
    int hashVal = 0;
    int i = 0;

    while (fileData[i] != '\0') {
        hashVal = (hashVal << 5) + fileData[i];
        i++;
    }

    return hashVal % hashSize;
}
