#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// Binary search tree node
typedef struct tree_node* tree_pointer;
typedef struct tree_node {
    char w1[100];
    char w2[100];
    tree_pointer left;
    tree_pointer right;
} tree_node;
tree_pointer root; // BST의 root를 가리키는 포인터 (global variable)

// 파일에서 단어들을 읽어 이진탐색트리 구성
int build_dictionary(char* fname);
// 트리에 (w1, w2) 자료 삽입
void bst_insert(char* w1, char* w2);
// 트리에서 키값이 w1인 자료를 검색, w2를 반환
char* bst_search(char* w1);
// 트리의 단어들을 inorder로 출력
void bst_show_inorder(tree_pointer ptr);