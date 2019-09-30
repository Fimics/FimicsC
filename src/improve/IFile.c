//
// Created by lipnegju on 2019-07-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define FILE_PATH "../resource/file.txt"

/**
 * 获得文件行数
 * @param file
 * @return
 */
int getFileLines(FILE *file){

    if (NULL==file) return -1;

    int lines=0;
    char buf[1024]={0};
    while (fgets(buf,1024,file)!=NULL){
       ++lines;
    }

    //恢复文件指针
    if(file!=NULL){
//        fseek(file,0,SEEK_SET);
          rewind(file);//文件指针恢复到开头
    }
    return lines;
}

void readData(FILE * file,char ** content ,int lines){

    if(NULL==file) return;
    if(lines<=0) return;
    if(content==NULL) return;

    //创建缓存区
    char buf[1024]={0};
    int index =0;

    while(fgets(buf,1024,file)!=NULL){
        //printf("%s\n",buf);
        int curLineLen =strlen(buf)+1;
        char *c = malloc(sizeof(char)*curLineLen+1);
        strcpy(c,buf);
        content[index++]=c;
        memset(buf,0,1024);
    }

}

void testReadData(){
    FILE * file = fopen(FILE_PATH,"r");
    if(NULL==file){
        printf("open file failed");
    }
    int lines = getFileLines(file);
    printf("line num %d\n",lines);

    char ** cLines = (char**)malloc(sizeof(char*)*lines);
    readData(file,cLines,lines);

    for (int i = 0; i <lines ; ++i) {
        printf("index %d value %s\n",i,cLines[i]);
    }}


int main(){
    testReadData();
}