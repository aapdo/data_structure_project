#ifndef DATA_STRUCTURE_PROJECT_DATA_H
#define DATA_STRUCTURE_PROJECT_DATA_H
#include "utils.h"


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


void enQueue(queue_pointer q, queue_node_pointer node);
queue_node_pointer deQueue(queue_pointer q);
bool is_queue_empty(queue_pointer q);
void bst_insert(tree_pointer root, word_pointer wordPointer);
void bst_show(tree_pointer ptr);
//sort data when end of read
void sortWords();

#endif //DATA_STRUCTURE_PROJECT_DATA_H
