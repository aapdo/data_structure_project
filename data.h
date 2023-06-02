#ifndef DATA_STRUCTURE_PROJECT_DATA_H
#define DATA_STRUCTURE_PROJECT_DATA_H

//최대 파일 개수
#define MAX_FILE_NUM 150
//파일 내 최대 줄 수
#define MAX_FILE_LINE_NUM 851
//파일 이름의 최대 글자 수
#define MAX_FILE_NAME_LEN 12
//각 줄의 최대 글자 수
#define MAX_FILE_LINE_LEN 150

char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];

typedef struct list_node* list_pointer;
typedef struct list_node{
    int line;
    list_pointer link;
} list_node;

typedef struct wordData* word_pointer;
typedef struct tree_node* tree_pointer;
typedef struct wordData {
    int docNumber;
    int cnt;
    list_pointer lines;
    tree_pointer bst;
} wordData;

typedef struct tree_node {
    word_pointer data;
    tree_pointer left;
    tree_pointer right;
} tree_node;

int hashSize = 10000;
word_pointer hashTable[hashSize][101]; // [hashsize][0~100], 0 : bst, 1~100 : doc

#endif //DATA_STRUCTURE_PROJECT_DATA_H
