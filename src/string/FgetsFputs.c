//
// Created by lipnegju on 2019-06-19.
//

#include "YString.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * char *fgets(char *s ,int size,FILE *stream)
 * 功能:
 * 从stream的文件内读入字符，保存到所指定的内存空间，直到出现换行字符，读到文件末尾
 * 或已经读了size-q个字符为止，最后会自动加上字符'\0'，作为字符串结束
 *
 * 参数
 * s :字指针
 * size:指定读取最大字符串的长度(size-1)
 * stream:文件指针,如果读取键盘的输入的字符串，固定写为stdin
 *
 * 返回值
 * 成功：
 * 失败：读到文件尾或出错NULL
 *-------------------------------------------------------------------
 * fputs(const char * str, FILE * stream)
 * 功能:
 *    把str所指定的字符串写入到stream所指写的文件中，字符串结束符'\0'不写入文件
 *
 * 参数：
 *   str:字符串
 *   stream:文件指针，如查把字符串输出到屏幕，固定写stdout
 * 返回值：
 *   成功：0
 *   失败：-1
 *
 * 注意
 *
 */
void fgetsFputs(){
    //    FILE * fileOut = "../resource/b.txt";

    char file [10];
    fgets(file,10,stdin);
    //puts(file);

    fputs(file,stdout);
}