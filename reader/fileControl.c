#include "fileControl.h"

int getInfo(){
    FILE* fp = fopen("../textFile/fileInfo.txt", "r");

    //file cnt
    int cnt = 0;
    int len;
    int i = 0;

    char buffer[MAX_FILE_NAME_LEN];

    // fileNames 배열 초기화
    for (int i = 0; i < MAX_FILE_NUM; ++i) {
        memset(fileNames[i], 0, sizeof(fileNames[i]));
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL ) {
        //\n 제거
        buffer[strcspn(buffer, "\n")] = '\0';
        len = strlen(buffer);

        // 파일 이름을 fileNames 배열에 복사
        strncpy(fileNames[i], buffer, len);
        cnt++;

        i++;
    }

    fclose(fp);

    return cnt;
}

void readFile(){
    FILE *fp;
    char buffer[MAX_FILE_LINE_LEN];
    int len;
    int fileNum = 0;

    for (int i = 0; i < MAX_FILE_NUM; ++i) {
        for (int j = 0; j < MAX_FILE_LINE_NUM; ++j) {
            memset(fileData[i][j], 0, sizeof(fileData[i][j]));
        }
    }

    fileNum = getInfo(fileNames);
    //printf("%s\n", fileNames[0]);
    for (int i = 0; i < fileNum; ++i) {
        char path[50] = "../textFile/";

        fp = fopen(strcat(path, fileNames[i]), "r");
        if (fp == NULL) {
            printf("Can't open file.\ni: %d file name: %s", i, strcat(path, fileNames[i]));
            exit(1);
        }

        int j = 0;

        while (fgets(buffer, sizeof(buffer), fp) != NULL ) {
            //\n 제거
            buffer[strcspn(buffer, "\n")] = '\0';
            len = strlen(buffer);


            strncpy(fileData[i][j], buffer, len);
            //printf("i: %d, %s\n", j, fileData[i][j]);
            j++;
        }
        //printf("doc%03d\n", i+1);

        fclose(fp);
    }
    printf("Total number of documents: %d\n", fileNum);
}