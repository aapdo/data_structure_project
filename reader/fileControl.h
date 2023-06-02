#ifndef DATA_STRUCTURE_PROJECT_FILECONTROL_H
#define DATA_STRUCTURE_PROJECT_FILECONTROL_H
//�ִ� ���� ����
#define MAX_FILE_NUM 150
//���� �� �ִ� �� ��
#define MAX_FILE_LINE_NUM 851
//���� �̸��� �ִ� ���� ��
#define MAX_FILE_NAME_LEN 12
//�� ���� �ִ� ���� ��
#define MAX_FILE_LINE_LEN 150

#include "../utils.h"

char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];

/**
 * ���� ������ �о���� �Լ�
 * @param ���� �̸����� ������ ����
 * @return ���� ����
 */
int getInfo();
void readFile();

#endif //DATA_STRUCTURE_PROJECT_FILECONTROL_H