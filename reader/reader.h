#ifndef DATA_STRUCTURE_PROJECT_READER_H
#define DATA_STRUCTURE_PROJECT_READER_H
#define MAX_FILE_NUM 150
#define MAX_FILE_LEN 20

#include <stdio.h>


FILE fOpen(char *fileName, char *mode);
void fClose(FILE fp);
char *getInfo();
void readFile(char fileData[][MAX_FILE_LEN])

#endif //DATA_STRUCTURE_PROJECT_READER_H
