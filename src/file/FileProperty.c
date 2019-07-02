//
// Created by lipnegju on 2019-07-03.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#define FILE_SRC "resource/aa.mp4"
#define FILE_DEST "resource/bb.mp4"
#define MAX_SIZE 1024*1024

/**
 * 获取文件属性
 */
void getFileProperty() {

    unsigned int startTime = time(NULL);

    FILE *src = fopen(FILE_SRC, "rb");
    FILE *dest = fopen(FILE_DEST, "wb");

    struct stat property = {0};
    stat(FILE_SRC, &property);
    printf("size %d\n", property.st_size);
    int fileLen = property.st_size;


    int mallocSize =fileLen<MAX_SIZE?fileLen:MAX_SIZE;

    char *ch = malloc(sizeof(char) * mallocSize);
    while (!feof(src)) {
        memset(ch, 0, MAX_SIZE);
        int len = fread(ch, 1, mallocSize, src);//fread 返回读的有效长度
        fwrite(ch, len, 1, dest);
    }

    fclose(src);
    fclose(dest);
    unsigned int endTime = time(NULL);

    printf("used time :%d\n", endTime - startTime);
}

void fileProperty() {
    getFileProperty();
}