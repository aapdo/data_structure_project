#ifndef DATA_STRUCTURE_PROJECT_DATA_H
#define DATA_STRUCTURE_PROJECT_DATA_H
#include "utils.h"

//최대 파일 개수
#define MAX_FILE_NUM 150
//파일 내 최대 줄 수
#define MAX_FILE_LINE_NUM 851
//파일 이름의 최대 글자 수
#define MAX_FILE_NAME_LEN 12
//각 줄의 최대 글자 수
#define MAX_FILE_LINE_LEN 150
//hashSize
#define hashSize 10000

char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];

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
    queue_pointer lines;
    tree_pointer bst;
} wordData;

typedef struct tree_node {
    word_pointer data;
    tree_pointer left;
    tree_pointer right;
} tree_node;

word_pointer hashTable[hashSize][101]; // [hashsize][0~100], 0 : bst, 1~100 : doc

void enQueue(queue_pointer q, queue_node_pointer node);
queue_node_pointer deQueue(queue_pointer q);
bool is_queue_empty(queue_pointer q);
void bst_insert(tree_pointer root, word_pointer wordPointer);
void bst_show(tree_pointer ptr);
//sort data when end of read
void sortWords();

#endif //DATA_STRUCTURE_PROJECT_DATA_H
