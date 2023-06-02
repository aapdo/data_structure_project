#ifndef DATA_STRUCTURE_PROJECT_FILECONTROL_H
#define DATA_STRUCTURE_PROJECT_FILECONTROL_H
//최대 파일 개수
#define MAX_FILE_NUM 150
//파일 내 최대 줄 수
#define MAX_FILE_LINE_NUM 851
//파일 이름의 최대 글자 수
#define MAX_FILE_NAME_LEN 12
//각 줄의 최대 글자 수
#define MAX_FILE_LINE_LEN 150

#include "../utils.h"

char fileNames[MAX_FILE_NUM][MAX_FILE_NAME_LEN];
char fileData[MAX_FILE_NUM][MAX_FILE_LINE_NUM][MAX_FILE_LINE_LEN];

/**
 * 파일 정보를 읽어오는 함수
 * @param 파일 이름들을 저장할 변수
 * @return 파일 개수
 */
int getInfo();
void readFile();

#endif //DATA_STRUCTURE_PROJECT_FILECONTROL_H