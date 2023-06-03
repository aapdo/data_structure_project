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

void enQueueDoc(queue_pointer q, int docNum){
    queue_node_pointer tmp = (queue_node_pointer) malloc(sizeof(queue_node));
    tmp->line = docNum;
    if (is_queue_empty(q)) {
        q->front = tmp;
        q->rear = tmp;
    }else{
        q->rear->link = tmp;
        q->rear = tmp;
    }
}
int deQueueDoc(queue_pointer q){
    int tmp;
    queue_node_pointer tmpNode;
    if (is_queue_empty(q)) {
        return 0;
    }else{
        tmp = q->front->line;
        tmpNode = q->front;
        if (q->front != q->rear) {
            q->front = q->front->link;
        }
        else{
            q->front = q->rear = NULL;
        }
        free(tmpNode);
        return tmp;
    }
}
bool is_queue_empty(queue_pointer q){
    return (q->front == NULL);
}
void bst_insert(tree_pointer root, word_pointer wordPointer){
    tree_pointer tmp = root;
    tree_pointer newNode = (tree_pointer) malloc(sizeof(tree_node));
    newNode->data = wordPointer;
    newNode->left = NULL;
    newNode->right = NULL;

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
            printf("%s\n",fileData[wordPointer->docNumber][lineNode->line] );
            //tmpChar = [j];
            /*
            if(tmpChar != '\0'){
                printf("%c",tmpChar);
                break;
            }
             */
            j++;
        }
        enQueue(q, lineNode);
    }
}

void sortWords(){
    int countDoc = 0;
    int docNum = 0;
    for (int i = 0; i < hashSize; i++)
    {
        countDoc = 0;
        //at least one lines
        docNum = deQueueDoc(hashTable[i][0]->lines);
        //no document
        if (docNum == 0) {
            continue;
        }
        //printf("hash: %d, doc: %d\n", i+1, docNum);
        //standard: wordData.cnt
        //node = wordData.
        /*
        countDoc++;
        bst_insert(hashTable[i][0]->bst, hashTable[i][j]);
        */
        if (hashTable[i][0]->bst != NULL) {
            bst_insert(hashTable[i][0]->bst, hashTable[i][docNum]);
        } else {
            hashTable[i][0]->bst = (tree_pointer) malloc(sizeof(tree_node));
            hashTable[i][0]->bst->data = hashTable[i][docNum];
            hashTable[i][0]->bst->right = NULL;
            hashTable[i][0]->bst->left = NULL;
        }
        hashTable[i][0]->cnt = countDoc;
    }
}

