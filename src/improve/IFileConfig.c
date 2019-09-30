//
// Created by lipnegju on 2019-07-15.
//

#include "IFileConfig.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define FILE_PATH "resource/config.ini"


//1.获取配置文件有效行数
int getLines(FILE *file){
    if(NULL==file) return -1;
    char buf[1024]={0};
    int lines=0;
    while(fgets(buf,1024,file)!=NULL){
        if(!isValidCurrentLine(buf)){
            continue;
        }
        memset(buf,0,1024);
        lines++;
    }

    //重置文件指针到文件头
//    fseek(file,0,SEEK_SET);
     rewind(file);
    return lines;
}

//2.加载配置文件
void loadConfigFile(const char * filePath, char *** data,int *lines){

    FILE *file = fopen(filePath,"r");
    if(NULL==file) return;

    int lineNum = getLines(file);
    //给每行数据开辟内存
    char **temp = malloc(sizeof(char*)*lineNum);
    int index = 0;

    char buf[1024]={0};
    while (fgets(buf,1024,file)){
        //如果返回false
        if(!isValidCurrentLine(buf)){
            continue;
        }

        temp[index] =malloc(strlen(buf)+1);//+1是因为有'\n'
        strcpy(temp[index],buf);
        //清空buf
        memset(buf,0,1024);
        index++;
    }

    //关闭文件
    if(file!=NULL){
        fclose(file);
    }

    *data=temp;
    *lines=lineNum;
}

//3.解析配置文件
void parseFile(char ** data,int lines, struct ConfigInfo ** info){

    struct ConfigInfo *configInfo = malloc(sizeof(struct ConfigInfo)*lines);
    memset(configInfo,0, sizeof(struct ConfigInfo)*lines);

    for (int i = 0; i <lines ; ++i) {
        char  *pos = strchr(data[i],':');
        strncpy(configInfo[i].key,data[i],pos-data[i]);
        strncpy(configInfo[i].value,pos+1,strlen(pos+1)-1);
        printf("index %d  key %-10s value %-10s\n",i,configInfo[i].key,configInfo[i].value);
    }

    //释放文件信息
    for (int j = 0; j <lines ; ++j) {
        if(data[j]!=NULL){
            free(data[j]);
        }
    }

    *info =configInfo;
}

//4.获取指定配置信息
char * getConfigInfoByKey(const char * key,struct ConfigInfo * info,int lines){

    for (int i = 0; i<lines ; i++) {
        if(strcmp(key,info[i].key)==0){
            return info[i].value;
        }
    }

    return NULL;
}

//5.释放配置文件信息
void destroyConfig(struct ConfigInfo * info){
     if(NULL==info) return;
     free(info);
     info==NULL;
}

//6.判断当前行是否有效
int isValidCurrentLine(const char * buf){
    if(buf==NULL || buf[0]=='#' || buf[0]=='\n' || strchr(buf,':')==NULL){
        return 0;
    }
    return 1;
}

void iFileConfig(){

    char ** data =NULL;
    struct ConfigInfo * configInfo;
    int lines=0;
    loadConfigFile(FILE_PATH,&data,&lines);
    parseFile(data,lines,&configInfo);
    char * username = getConfigInfoByKey("database",configInfo,lines);
    printf("lines %d\n",lines);
    printf("username is %s\n",username);
    destroyConfig(configInfo);
}