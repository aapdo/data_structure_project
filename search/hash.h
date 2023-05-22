#ifndef DATA_STRUCTURE_PROJECT_HASH_H
#define DATA_STRUCTURE_PROJECT_HASH_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100

typedef struct Bucket* Bucket_pointer;
// �ؽ� ���̺��� ��Ŷ ����ü
typedef struct Bucket {
    char key[50];
    int count;
    struct Bucket* next;
} Bucket;

typedef struct HashTable* HashTable_pointer;
// �ؽ� ���̺� ����ü
typedef struct HashTable {
    Bucket_pointer table[TABLE_SIZE];
} HashTable;

HashTable_pointer ht;
char word[50], cleanedWord[50], searchWord[50];
int cleanedIndex = 0, count;

// �ؽ� �Լ�
unsigned int hash(const char* key);
// �ؽ� ���̺� �ʱ�ȭ
void initializeHashTable(HashTable_pointer ht);
// Ű-�� ���� �ؽ� ���̺� ���� �Ǵ� ������Ʈ
void insertOrUpdate(HashTable_pointer ht, const char* key);
// Ű�� �ش��ϴ� ��(���� Ƚ��) ��ȯ
int getCount(HashTable_pointer ht, const char* key);

#endif //DATA_STRUCTURE_PROJECT_HASH_H
