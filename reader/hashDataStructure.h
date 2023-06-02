#ifndef DATA_STRUCTURE_PROJECT_HASHDATASTRUCTURE_H
#define DATA_STRUCTURE_PROJECT_HASHDATASTRUCTURE_H

#include "../utils.h"





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
