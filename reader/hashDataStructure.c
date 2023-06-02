#include "hashDataStructure.h"

void insert_list(list_pointer head, int lineNum){
    list_pointer newNode = (list_pointer)malloc(sizeof(list_node));
    newNode->line = lineNum;
    newNode->link = head->link;
    head->link = newNode;
}

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

void hashInsert(){
    //hashing
    int hashValue = 3;
    //doc num
    int tmpDocNum = 3;
    //line num
    int tmpLineNum = 3;

    //word data
    hashTable[hashValue][tmpDocNum]->cnt++;
    insert_list(hashTable[hashValue][tmpDocNum]->lines, tmpLineNum);
    hashTable[hashValue][0]->cnt++;
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

void search(){
    char* inputStr;
    int hashValue = hash(inputStr);

    bst_show(hashTable[hashValue][0]);
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