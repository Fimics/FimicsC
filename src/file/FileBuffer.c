//
// Created by lipnegju on 2019-07-03.
//


#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

/**
 * 文件缓存区
 */

void fileBuffer() {
    char fileName[256];
    printf("请您输入一个需要创建的文件：\n");
    scanf("%s", fileName);
    getchar();
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        return;
    }
    //scanf("%[^\n]",buf);
    //fgets()

    char buf[1024];
    while (1) {
        memset(buf, 0, 1024);
        //scanf("%[^\n]", buf);
        fgets(buf, 1024, stdin);
        //comm=exit代表录入结束
        if (strncmp("comm=exit", buf, 9) == 0) {
            break;
        }
//        int i = 0;
//        while (buf[i] != '\0') {
//            fputc(buf[i++], fp);
//            //i++;
//
//
//        }

        fputs(buf,fp);
        fflush(fp);
    }


    fclose(fp);
}