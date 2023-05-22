#ifndef DATA_STRUCTURE_PROJECT_HASH_H
#define DATA_STRUCTURE_PROJECT_HASH_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100

typedef struct Bucket* Bucket_pointer;
// 해시 테이블의 버킷 구조체
typedef struct Bucket {
    char key[50];
    int count;
    struct Bucket* next;
} Bucket;

typedef struct HashTable* HashTable_pointer;
// 해시 테이블 구조체
typedef struct HashTable {
    Bucket_pointer table[TABLE_SIZE];
} HashTable;

HashTable_pointer ht;
char word[50], cleanedWord[50], searchWord[50];
int cleanedIndex = 0, count;

// 해시 함수
unsigned int hash(const char* key);
// 해시 테이블 초기화
void initializeHashTable(HashTable_pointer ht);
// 키-값 쌍을 해시 테이블에 삽입 또는 업데이트
void insertOrUpdate(HashTable_pointer ht, const char* key);
// 키에 해당하는 값(출현 횟수) 반환
int getCount(HashTable_pointer ht, const char* key);

#endif //DATA_STRUCTURE_PROJECT_HASH_H
