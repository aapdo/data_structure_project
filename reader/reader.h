#ifndef DATA_STRUCTURE_PROJECT_READER_H
#define DATA_STRUCTURE_PROJECT_READER_H
#include "fileControl.h"
#include "bst.h"

//hash 테이블의 Element
typedef struct Bucket {
    tree_pointer root;
    char key[50];
    int count;
    struct Bucket* next;
} Bucket;

void read();

#endif //DATA_STRUCTURE_PROJECT_READER_H
