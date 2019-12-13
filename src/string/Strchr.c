//
// Created by lipnegju on 2019-06-21.
//

#include <string.h>
#include <stdio.h>

/**
 * strchr(const char *s,int c) ,在字符串s中查找c第一次出现的位置
 * strstr(const char *s, const char *c)在s中查找字符串c出现的位置
 */

void strchr1(){
    char s[] ="hello world ,e ,9 hello world ,jump";
    char c = 'j';

//    char * pOne = strchr(s,c);
//    printf("one find index %s\n",pOne);
    char * pMany = strstr(s,"e");
    printf("many find index %s\n",pMany);
}

void strFind(){
    strchr1();
}

#if 0
int main(){
    strFind();
}
#endif