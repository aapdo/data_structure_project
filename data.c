#include "data.h"
char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];
word_pointer hashTable[hashSize][101]; // [hashsize][0~100], 0 : bst, 1~100 : doc
int compare = 0; // �񱳿���Ƚ��
char oneWord[15];

void enQueue(queue_pointer q, queue_node_pointer node){
    if (is_queue_empty(q)) {
        q->front = node;
        q->rear = node;
    }else{
        q->rear->link = node;
        q->rear = node;
    }
}
queue_node_pointer deQueue(queue_pointer q){
    queue_node_pointer tmp;
    if (is_queue_empty(q)) {
        return NULL;
    }else{
        tmp = q->front;
        if (q->front != q->rear) {
            q->front = q->front->link;
        }
        else{
            q->front = q->rear = NULL;
        }
        return tmp;
    }
}
bool is_queue_empty(queue_pointer q){
    return (q->front == NULL);
}
void bst_insert(tree_pointer root, word_pointer wordPointer){
    if (root == NULL) {
        tree_pointer newNode = (tree_pointer) malloc(sizeof(tree_node));
        newNode->data = wordPointer;
        root = newNode;
        return;
    }

    tree_pointer tmp = root;
    tree_pointer newNode = (tree_pointer) malloc(sizeof(tree_node));
    newNode->data = wordPointer;

    int tmpKey = tmp->data->cnt;
    int key = wordPointer->cnt;

    while (1) {
        if (tmpKey > key) {
            if (tmp->left == NULL) {
                tmp->left = newNode;
                break;
            }
            tmp = tmp->left;
        } else if(tmpKey < key) {
            if (tmp->right == NULL) {
                tmp->right = newNode;
                break;
            }
            tmp = tmp->right;
        }
    }
}

/**
== serach ==
------------ Result ------------
Keyword: computer
Total documents: 3
==============


 =========== bst_show ============
<doc002.txt> (computer: 2)
In computer science, data is any
for use with a computer[1].

<doc001.txt> (computer: 1)
A "data structure" is a way of storing data in a computer so that it can be used efficiently.

<doc004.txt> (computer: 1)
A computer is a machine for manipulating data
 =========== bst_show ============

Total number of comparison: 25
 * @param ptr
 */
void bst_show(tree_pointer ptr){
    if(ptr == NULL) return;
    bst_show(ptr->left);
    bst_show(ptr->right);

    word_pointer wordPointer = ptr->data;
    int wordCnt = wordPointer->cnt;
    char tmpChar;
    queue_pointer q = wordPointer->lines;
    queue_node_pointer lineNode;

    printf("<doc%03d.txt> (%s: %d)\n", wordPointer->docNumber, oneWord, wordCnt);
    for (int i = 0; i < wordCnt; ++i) {
        lineNode = deQueue(q);
        int j = 0;
        while(1){
            tmpChar = fileData[wordPointer->docNumber][lineNode->line][j];
            if(tmpChar != '\0'){
                printf("%c",tmpChar);
                break;
            }
            j++;
        }
        printf("\n");
        enQueue(q, lineNode);
    }
}

void sortWords(){
    int countDoc = 0;
    for (int i = 0; i < hashSize; i++)
    {
        countDoc = 0;
        //at least one lines
        if (hashTable[i][0]->cnt != 0)
        {
            //hashTable[i][0]->bst = (tree_pointer) malloc(sizeof(tree_node));
            //get bst
            tree_pointer tmp = hashTable[i][0]->bst;
            for (int j = 1; j < 101; j++)
            {
                if(hashTable[i][j]->cnt != 0){
                    //standard: wordData.cnt
                    //node = wordData.
                    countDoc++;
                    bst_insert(tmp, hashTable[i][j]);
                }
            }
            hashTable[i][0]->cnt = countDoc;
        }
    }
}

