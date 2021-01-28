//
// Created by lipnegju on 2019-07-11.
//

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//-----------------------字符串初始化--------------------------------
void testString(){
    char arr0 [] ={'h','e','l','l','o'};
    printf("%s\n",arr0);

    char arr [] ={'h','e','l','l','o',0};
    printf("%s\n",arr);

    char arr1 [] ={'h','e','l','l','o','\0'};
    printf("%s\n",arr1);

    char arr2 [100] ={'h','e','l','l','o'};// 大小是100 ，但只有5个字符，剩下的会初始化为0
    printf("%s\n",arr2);

    char arr3[]="hello";
    printf("%s\n",arr3);
    printf("sizeof str%d\n", sizeof(arr3));  //6
    printf("strlen str%d\n",strlen(arr3)); //5
}



//-----------------------字符串拷贝--------------------------------

/**
 * 一个字符一个字符的拷贝
 */
void stringCopy(char * dest, char *src){
    int len = strlen(src);
    for (int i = 0; i <len ; ++i) {
        dest[i]=src[i];
    }

    dest[len]='\0';
}

/**
 * 指针方式拷贝
 */
void stringCopy1(char *dest ,char * src){
//    while(*src){
    while(*src!='\0'){
        *dest=*src;
        dest++;
        src++;
    }
    dest='\0';
}

/**
 *
 */
void stringCopy2(char *dest ,char * src){
    while (*dest++=*src++);
}

void testStringCopy(){
  char* source ="hello world";
  char buf[1024]={0};
    //一个字符一个字符的拷贝
//  stringCopy(buf,source);
//指针操作方式拷贝
//  stringCopy1(buf,source);

  stringCopy2(buf,source);
  printf("%s\n",buf);
}



//-----------------------字符串反转--------------------------------

void resverseString(char *str){
    if(NULL==str) return;

    int len = strlen(str);
    int start =0;
    int end = len-1;

    while (start<end){
        char  temp = str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }

}

void testReverseString(){
    char  str [] ="hello world";
    resverseString(str);
    printf("%s\n",str);
}


//-----------------------字符串格式化sprintf--------------------------------

/**
 * printf 输出到标准输出设备
 * sprintf 输出到了缓存区
 *
 * int sprintf(char *str,const char * format,...)
 * 功能:
 *    根据参数format字符串来转换并格式化数据，然后把结果转出到str指定的空间中，直到出现字符串结束符'\0'为止
 * 参数:
 *    str:字符串首地址
 *    format:字符串格式，用法和printf()一样
 */
void testStringFormat(){
   //1.格式化字符串
   char buf [1024]={0};
   sprintf(buf,"你好%s,欢迎加入我们!","John");
   printf("%s\n",buf);

   //2.拼接字符串
    char  *s1 ="hello";
    char  *s2 =" world";
    memset(buf,0,1024);
    sprintf(buf,"%s %s",s1,s2);
    printf("%s\n",buf);

    //3数字转成字符串
    int number =666;
    memset(buf,0,1024);
    sprintf(buf,"%d",number);
    printf("buf %s\n",buf);


    //4.内存分配
    char ** p = malloc(sizeof(char *)*5);
    for (int i = 0; i <5 ; ++i) {
        p[i]=malloc(64);
        memset(p[i],0,64);
        sprintf(p[i],"Nane_%d",i);
    }

    for (int j = 0; j <5 ; ++j) {
        printf("%s\n",p[j]);
    }
    //释放内存
    for (int k = 0; k <5 ; ++k) {
        if(p[k]!=NULL){
            free(p[k]);
            p[k]=NULL;
        }
    }

    if(p!=NULL){
        free(p);
        p=NULL;
    }

    //5.设置宽度，右对齐
    memset(buf,0,1024);
    sprintf(buf,"%8d\n",number);
    printf("%s\n",buf);

    //6.设置宽度，左对齐
    memset(buf,0,1024);
    sprintf(buf,"%-8d\n",number);
    printf("%s\n",buf);

    //7.转成16进制字符串 小写
    memset(buf,0,1024);
    sprintf(buf,"0x%x",number);
    printf("buf:%s\n",buf);

    //7.转成8进制字符串
    memset(buf,0,1024);
    sprintf(buf,"0%o",number);
    printf("buf:%s\n",buf);

}

void stringFormat(){
    testStringFormat();
}

//-----------------------sscanf--------------------------------

/**
 * int sscanf(constt char *str,const char *format ...)
 * 从指定的字符串读取数据，并根据参数format来转换并格式化数据
 *
 *1. %*s %*d 跳过字符串，跳过数字
 *2.%[a-z]匹配a-z中的字符(尽可能多的匹配)
 *3.%[abc] 匹配a,b,c中的一员(贪婪模式)
 *4.%[^a]匹配非a 任意字符
 *
 */


void testSscanf(){
    char *str ="12345abcde";
    char buf[1024]={0};
    sscanf(str,"%*d%s",buf);
    printf("buf %s\n",buf);
}

#if 0

int main(){
    testString();
//    testStringCopy();
//    testReverseString();
//    stringFormat();
//    testSscanf();
}

#endif