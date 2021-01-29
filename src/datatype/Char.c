//
// Created by pengju.li on 2019-06-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>

void getCharPutChar() {
    char ch;
    while ((ch = getchar()) != 'q') {
        putchar(ch);
    }

//    while ((ch=getchar()!=EOF))// 判断文件末尾
}


void testFileEof() {
    int ch;
    FILE *fp;
    char fname[50];         // to hold the file name

    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); // open file for reading
    if (fp == NULL)         // attempt failed
    {
        printf("Failed to open file. Bye\n");
        exit(1);            // quit program
    }
    // getc(fp) gets a character from the open file
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}

#if 0
int main() {
//    getCharPutChar();
    testFileEof();
    return 0;
}

#endif