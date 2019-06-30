//
// Created by lipnegju on 2019-06-30.
//

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*
字符串的标准输入输出
scanf("%d,%d,%d",ch)    printf("%0d",1);
格式化字符串   char arr[]="相约98"   char ch[10]="恋曲"; int a=1990;
sscanf() sprintf()   数据类型  char *    format
sscanf(arr,"%s%d",ch,&a);
sprintf(arr,"%s%d",ch,a);

格式化文件读写 数据类型  FILE *  fp    format
fscanf() fprintf()
fscanf(fp,"%s%d",ch,&a);
fprintf(fp,"%s%d",ch,a);


*/
void testFprintf() {
    FILE *fp1 = fopen("resource/a.txt", "w");
    if (!fp1)
        return ;

    fprintf(fp1, "%d+%d=%d\n", 1, 2, 3);

    fclose(fp1);
}

void testFprintf1() {
    FILE *fp1 = fopen("resource/a.txt", "r");
    if (!fp1)
        return ;
    int a, b, c;
    fscanf(fp1, "%d+%d=%d\n", &a, &b, &c);

    printf("%d   %d   %d\n", a, b, c);


    fclose(fp1);
}

void testFprintf2() {
    FILE *fp1 = fopen("resource/a.txt", "r");
    if (!fp1)
        return ;


    int a, b, c;
    char ch;
    for (int i = 0; i < 100; i++) {
        fscanf(fp1, "%d%c%d=\n", &a, &ch, &b);
        printf("%d%c%d=\n", a, ch, b);
    }
    fclose(fp1);
}

void fileFscanf() {

}