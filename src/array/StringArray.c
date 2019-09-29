//
// Created by lipnegju on 2019-06-22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  SIZE 30

/**
 * 1.c没有字符串这种数据类型，可以通过char的数组来替代
 * 2.字符串一定是一个char数组，但char的数组未必是字符串
 * 3.数字0（和字符串'\0'等价）结尾的char数组就是一个字符串，但如果char数组没有以数字0结尾，那么就不是一个字符串
 *  ，只是普通字符数组，所以字符串是一种特殊的char数组
 */
void stringArray(){

    char arr []={'a','b','c'};//字符数组
    char  arr1[] ={'a','b','\0'};//字符串
    char  arr2 [] ="hello";//字符串

    // %s会接收字符串结束标志'\0'之前所有字符，在ASCII中就是数字0
    printf("%s",arr1);
    printf("arr size %d,arr1 size %d,arr2 size %d\n", sizeof(arr), sizeof(arr1), sizeof(arr2));

    int arr2Len = sizeof(arr2)/ sizeof(char);
    for (int i = 0; i < arr2Len; ++i) {
        printf("%c\n",arr2[i]);
    }

    printf("arr %s,size of %d,len is %d\n",arr, sizeof(arr),strlen(arr));
    printf("arr1 %s,size of %d,len is %d\n",arr1, sizeof(arr1),strlen(arr1));
    printf("arr2 %s,size of %d,len is %d\n",arr2, sizeof(arr2),strlen(arr2));
}

#if 1
int main(){
    stringArray();
}

#endif