//
// Created by lipnegju on 2019-07-03.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <time.h>

#define FILE_SRC "resource/a.txt"
#define MAX_SIZE 1024*1024

void testAccess(){
    FILE *fp = fopen(FILE_SRC,"r");
    if(!fp)
        return;

    //fseek(fp,6,SEEK_SET);//从头移动
    fseek(fp,-6,SEEK_END);//从文件尾移动
    char  ch;
    while (!feof(fp)){
        ch = fgetc(fp);
        if(ch!='\0'&&ch!=EOF){
            printf("%c",ch);
        }
    }

    int position =ftell(fp);
    printf("current position %d\n",position);

//    void rewind(FILE *stream);把文件流（文件光标）的读写位置移动到文件开头
}

void fileRandomAccess(){
testAccess();
}