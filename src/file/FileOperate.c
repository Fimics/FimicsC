//
// Created by lipnegju on 2019-06-30.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 文件操作
 */

void fileOpenClose() {

    /**
     * https://blog.csdn.net/djw931017/article/details/87832073
     * 方法一：回到父目录 ../a.txt;
     *  FILE * fp = fopen("../src/file/aa.txt","r");
     * 方法二,在Run->Edit Configurations中修改Working directory为当前绝对路径 /Users/lipengju/code/c/FimicsC
     *  FILE * fp = fopen("src/file/aa.txt","r");
     */

    /**
     *
     * r 以只读形式打开文件  不会创建新文件，如果文件不存在会报错
     * w 以写的方式打开文件 文件不存在会创建新文件 如果文件里面有内容会覆盖原始内容
     * a 以追加方式打开文件 文件不存在会创建新文件 在文件末尾追加内容
    */
    FILE *fp = fopen("../resource/a.txt", "r");
    if (fp == NULL) {
        /**
         * case 1:找不到文件
         * case 2: 没有权限
         * case 3:程序打开文件超出上限 一个程序最多打开65535个文件
         */
        printf("%s\n", "file open filed.");
        return;
    }

    printf("%s\n", "file open success.");
    //把一个字符写入文件中
    fputc('a', fp);

    //从文件中读取一个字符
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }


    //文件关闭
    //fclose(fp);


}

/**
 * int fputs(const char *str, FILE * stream)
 * 功能：指到str所指定的字符串写到stream指定的文件中，字符串结束符'\0'不写入文件
 */
void testFputs() {

    char *p = "hello world";
    FILE *fp = fopen("../resource/fputs.txt", "w");
    if (!fp)
        return;

    fputs(p, fp);
    fclose(fp);
}

/**
 * 行读取
 */
void testFgets() {
    FILE *fp = fopen("resource/fputs.txt", "r");
    if (!fp)
        return;
//    //块读取
//    char buf[500];//
//    fgets(buf, 500, fp);
//    printf("第一次读取结果：%s\n", buf);
//    memset(buf, 0, 5);
//
//    fgets(buf, 5, fp);
//    printf("第二次读取结果：%s\n", buf);
//
//    memset(buf, 0, 5);
//
//    fgets(buf, 5, fp);
//    printf("第三次读取结果：%s\n", buf);
//
//
//    fgets(buf, 5, fp);
//    printf("第四次读取结果：%s\n", buf);
//    fclose(fp);

    //char buf[1024*1024];//1M
    char *buf = malloc(sizeof(char) * 1024);

    //feof判断文件流是否到结尾  EOF 判断字符是否到结尾
    while (feof(fp) == 0) {
        memset(buf, 0, 1024);
        fgets(buf, 1024, fp);
        printf("%s", buf);
    }
}

#if 0

int main() {
    fileOpenClose();
    testFputs();
    testFgets();
}

#endif