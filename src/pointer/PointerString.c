//
// Created by lipnegju on 2019-06-26.
//



#include <printf.h>
#include <string.h>

void pointerStringTest1() {

    char arr[] = "hello world";
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char *p;
    p = arr;
    *p = 'A';
    p++;
    *p = 'B';
    printf("%s\n", p);
    printf("%s\n", arr);
    printf("%d\n", sizeof(arr));//12
    printf("%d\n", sizeof(arr1));//40
    printf("%d\n", strlen(arr));//11
    printf("%d\n", strlen(p));//8
}

void pointerStringTest2() {

    char *arr = "hello world";//字符串常量 不可以被修改，
    char arr1[] = "hello world";//字符串数组 ，可以改变他的内容，存在栈区
    printf("%s\n", arr);
    printf("%c\n", arr[0]);
    char *p = arr;
    printf("%p\n", p);

    //字符串常量是一个常量的数组，可以读取字符或字符串，但不能修改
//    p[0]='A';
//    *p='A';
    printf("%s\n", arr);
}

void stringAppend(char *arr, char *s) {

    while (*arr)
        arr++;

    while (*arr++ = *s++);

}

#if 0

int main() {
//    pointerStringTest1();
    pointerStringTest2();
//    char arr[100] = "hello";
//    char *s = "world";
//    stringAppend(arr, s);
//    printf("%s\n", arr);
}

#endif