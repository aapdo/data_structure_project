#ifndef DATA_STRUCTURE_PROJECT_FILECONTROL_H
#define DATA_STRUCTURE_PROJECT_FILECONTROL_H
//�ִ� ���� ����
#define MAX_FILE_NUM 150
//���� �� �ִ� �� ��
#define MAX_FILE_LINE_NUM 20
//���� �̸��� �ִ� ���� ��
#define MAX_FILE_NAME_LEN 10
//�� ���� �ִ� ���� ��
#define MAX_FILE_LINE_LEN 100

#include <stdio.h>
#include <string.h>

/**
 * ���� ������ �о���� �Լ�
 * @param ���� �̸����� ������ ����
 * @return ���� ����
 */
int getInfo( char [][MAX_FILE_NAME_LEN] );
void readFile(char fileData[][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN], char fileNames[][MAX_FILE_NAME_LEN]);

#endif //DATA_STRUCTURE_PROJECT_FILECONTROL_H