//
// Created by lipnegju on 2019-07-03.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILE_SRC  "resource/aa.mp4"
#define FILE_DEST "resource/bb.mp4"
#define MAX_SIZE 1024*1024*10

/**
 * 一个字节一个字节拷贝 17s
 */
void copyCharByChar(){

    unsigned int startTime = time(NULL);

    FILE * src = fopen(FILE_SRC,"rb");
    FILE * dest = fopen(FILE_DEST,"wb");

    char ch;
    while (!feof(src)){
        ch =fgetc(src);
        fputc(ch,dest);
    }

    fclose(src);
    fclose(dest);
    unsigned int endTime = time(NULL);

    printf("used time :%d\n",endTime-startTime);
}


void copyLineByLine(){
    unsigned int startTime = time(NULL);

    FILE * src = fopen(FILE_SRC,"rb");
    FILE * dest = fopen(FILE_DEST,"wb");

    char ch[1024];
    while (!feof(src)){
        memset(ch,0,1024);
        int len =fread(ch,1,1024,src);//fread 返回读的有效长度
        fwrite(ch,len,1,dest);
    }

    fclose(src);
    fclose(dest);
    unsigned int endTime = time(NULL);

    printf("used time :%d\n",endTime-startTime);
}


void copyByMalloc(){
    unsigned int startTime = time(NULL);

    FILE * src = fopen(FILE_SRC,"rb");
    FILE * dest = fopen(FILE_DEST,"wb");

    char *ch=malloc(sizeof(char)*MAX_SIZE);
    while (!feof(src)){
        memset(ch,0,MAX_SIZE);
        int len =fread(ch,1,MAX_SIZE,src);//fread 返回读的有效长度
        fwrite(ch,len,1,dest);
    }

    fclose(src);
    fclose(dest);
    unsigned int endTime = time(NULL);

    printf("used time :%d\n",endTime-startTime);
}

void copyBigFile(){
//    copyCharByChar();
//copyLineByLine();
copyByMalloc();
}