//
// Created by lipnegju on 2019-07-15.
//

//防止头文件重复导入
#pragma once

#include <stdio.h>


struct ConfigInfo{
    char key[64];
    char value[128];
};

/**
 * 目的为了在C++中能够调用C写的函数
 */
#include <_stdio.h>

#ifdef __cplusplus
    extern "C"{
#endif

//1.获取配置文件有效行数
int getLines(FILE *file);

//2.加载配置文件
void loadConfigFile(const char * filePath, char *** data,int *lines);

//3.解析配置文件
void parseFile(char ** data,int lines, struct ConfigInfo ** info);

//4.获取指定配置信息
char * getConfigInfoByKey(const char * key,struct ConfigInfo * info,int lines);

//5.释放配置文件信息
void destroyConfig(struct ConfigInfo * info);

//6.判断当前行是否有效
int isValidCurrentLine(const char * lineBuf);


#ifdef __cplusplus
}
#endif