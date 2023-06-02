#ifndef DATA_STRUCTURE_PROJECT_UTILS_H
#define DATA_STRUCTURE_PROJECT_UTILS_H

//global variable,
//standard lib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
//�ִ� ���� ����
#define MAX_FILE_NUM 150
//���� �� �ִ� �� ��
#define MAX_FILE_LINE_NUM 851

//���� �̸��� �ִ� ���� ��
#define MAX_FILE_NAME_LEN 13

//�� ���� �ִ� ���� ��
#define MAX_FILE_LINE_LEN 200
//hashSize
#define hashSize 10000

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

extern char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
extern char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];
extern word_pointer hashTable[hashSize][101]; // [hashsize][0~100], 0 : bst, 1~100 : doc
extern int compare; // �񱳿���Ƚ��
extern char oneWord[15];

#endif //DATA_STRUCTURE_PROJECT_UTILS_H
