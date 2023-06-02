#ifndef DATA_STRUCTURE_PROJECT_HASHDATASTRUCTURE_H
#define DATA_STRUCTURE_PROJECT_HASHDATASTRUCTURE_H

#include "../utils.h"

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
    /*
    must init
    lines = (list_pointer)malloc(sizeof(list_node));
    */
} wordData;

typedef struct tree_node {
    word_pointer data;
    tree_pointer left;
    tree_pointer right;
} tree_node;

const int hashSize = 10000;
word_pointer hashTable[hashSize][101];



/**
 * �ؽ� ���̺��� �ܾ�� �˻���
 * �����δ� ��Ŷ�� ��
 * ��Ŷ���� �켱 wordData�迭�� �������.
 * ������ 100�� �����Ƿ� �� ������ wordData�� �ִ°�
 * wordData�� ���� ��ȣ, ī��Ʈ, lines(��ũ�� ����Ʈ)�� ����
 * �� �� 0�� wordData�� BST�� ������ �ְ�
 * 1~100�� wordData�� �� �������� �ش� �ܾ�.
 *
 * ������ �� ������
 * �ܾ�� �ؽ� => Ű
 * �ܾ �� ��° ���������� wordData�� ����
 * wordData�� ī��Ʈ +1 ���ְ�
 * lines�� �� ��° ������ insert
 *
 *
 */

void insert_list(list_pointer head, int lineNum);
void bst_insert(tree_pointer root, word_pointer wordPointer);
void bst_show(tree_pointer ptr);

//hash init
void hashInit();
//hashing and insert data
void hashInsert();
//sort data when end of read
void sortWords();
//search when user input word
void search();



#endif //DATA_STRUCTURE_PROJECT_HASHDATASTRUCTURE_H
