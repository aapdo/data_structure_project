#ifndef DATA_STRUCTURE_PROJECT_DATA_H
#define DATA_STRUCTURE_PROJECT_DATA_H
#include "utils.h"


/**
 * 해시 테이블은 단어로 검색함
 * 값으로는 버킷이 들어감
 * 버킷에는 우선 wordData배열이 만들어짐.
 * 문서가 100개 있으므로 각 문서별 wordData가 있는것
 * wordData는 문서 번호, 카운트, lines(링크드 리스트)가 있음
 * 이 때 0번 wordData는 BST를 가지고 있고
 * 1~100번 wordData는 각 문서에서 해당 단어.
 *
 * 색인을 할 때에는
 * 단어로 해싱 => 키
 * 단어가 몇 번째 문서인지로 wordData에 접근
 * wordData의 카운트 +1 해주고
 * lines에 몇 번째 줄인지 insert
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

void enQueueDoc(queue_pointer q, int docNum);
int deQueueDoc(queue_pointer q);

#endif //DATA_STRUCTURE_PROJECT_DATA_H
