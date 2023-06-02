#include "data.h"

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
    return q->front == NULL;
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

void bst_show(tree_pointer ptr){
    if(ptr == NULL)
}

void sortWords(){
    for (int i = 0; i < hashSize; i++)
    {
        //at least one lines
        if (hashTable[i][0]->cnt != 0)
        {
            //hashTable[i][0]->bst = (tree_pointer) malloc(sizeof(tree_node));
            //get bst
            tree_pointer tmp = hashTable[i][0]->bst;
            for (int j = 1; j < 101; j++)
            {
                //standard: wordData.cnt
                //cnt 기준으로 bst 삽입.
                //node = wordData.
                bst_insert(tmp, hashTable[i][j]);
            }
        }
    }
}

