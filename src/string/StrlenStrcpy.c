//
// Created by lipnegju on 2019-06-20.
//


#include <stdio.h>
#include <string.h>

/**
 * 字符串有效长度
 */
void strLen() {
//    char  arr[] ="hello";
    char arr[] = {'h', 'e', 'l', 'l', 'o'};//strlen 不能处理字符数组
    int len = strlen(arr);
    printf("字符串的有效长度：%d", len); //忽略字符串结束符号
    printf("字符串的长度:%d", sizeof(arr));
}

/**
 * strcpy ,strncpy(dest,src,n) 拷贝n个
 */
void strcpy1() {
    char arr1[] = "hello world";
    char arr2[100];
    //参数: 1目标字符串，2源字符串 ,会拷贝'\0'
//  if(strcpy(arr2,arr1)){
//      printf("%s",arr2);
//      printf("字符串的长度:%d", sizeof(arr2));
//  }

// srcncpy不会拷贝'\0' 可以手到加一个
    if (strncpy(arr2, arr1, 3) != NULL) {
        arr2[3] = '\0';
        printf("%s", arr2);
        printf("字符串的长度:%d", sizeof(arr2));
    }
}

/**
 * strcat ,strncat 会把'\0'追加过去
 *字符串追加 stringBuffer |stringBuilder
 */
void strcat1() {
    char arr1[22] = "hello";
    char arr2[] = "world";
    //把2的内容追加到1里
    strcat(arr1, " ");
    //strcat(arr1,arr2);
    //有限追加
    strncat(arr1, arr2, 2);
    printf("arr1 %s\n", arr1);
    printf("arr2 %s\n", arr2);

}

/**
 * strcmp strncmp
 * 比较字符的ASSIC码,不同的操作系统返回的值不同，有的返回ASSIC差值，有的返回 0，1 -1
 */

void strcmp1() {
    char arr1[] = "hello12dd";
    char arr2[] = "hello1";
    //把2的内容追加到1里
    //int result =strcmp(arr1,arr2);
    int result = strncmp(arr1, arr2, 7);
    printf("result %d\n", result);
}


#if 0

int main() {
    strLen();
//    strcpy1();
//    strcat1();
//    strcmp1();
}

#endif