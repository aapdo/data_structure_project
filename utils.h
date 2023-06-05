#ifndef DATA_STRUCTURE_PROJECT_UTILS_H
#define DATA_STRUCTURE_PROJECT_UTILS_H

//global variable,
//standard lib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//maximum file number
#define MAX_FILE_NUM 150
//maximum number of line in file
#define MAX_FILE_LINE_NUM 851
//maximum file name length
#define MAX_FILE_NAME_LEN 13
//maximum sentence length
#define MAX_FILE_LINE_LEN 200
//maximum word length
#define MAX_WORD_LEN 10
//hashSize
<<<<<<< Updated upstream
#define hashSize 70000
=======
#define hashSize 100000
>>>>>>> Stashed changes


typedef struct queue_node* queue_node_pointer;
typedef struct queue_node{
    int line;
queue_node_pointer link;
} queue_node;

typedef struct queue* queue_pointer;
typedef struct queue{
    queue_node_pointer front, rear;
} queue;

typedef struct wordData* word_pointer;
typedef struct tree_node* tree_pointer;
typedef struct wordData {
    int docNumber;
    int cnt;
    char *word;
    queue_pointer lines;
    tree_pointer bst;
} wordData;

typedef struct tree_node {
    word_pointer data;
    tree_pointer left;
    tree_pointer right;
} tree_node;

extern char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
extern char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];
extern word_pointer hashTable[hashSize][101]; // [hashsize][0~100], 0 : bst, 1~100 : doc
extern int compare; // �񱳿���Ƚ��
extern char oneWord[15];
extern char oneLine[MAX_FILE_LINE_LEN];
extern int totalIndexedWords;

#endif //DATA_STRUCTURE_PROJECT_UTILS_H
