//
// Created by pengju.li on 2019-07-12.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 指针做为函数参数
 */

void allocateSpace11(int **temp) {
    int *arr = malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    *temp = arr;

    if (arr != NULL) {
        free(arr);
    }
}

void freeSpace0(void * p){
    if(p==NULL) return;

    free(p);
    p=NULL;
}


/**
 * 释放被调函数的指针
 * @param p
 */
void freeSpace01(int **p) {
    if (p == NULL) return;
    free(*p);
    *p = NULL;
}

void printArrayii(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("index : %d value %d\n", i, arr[i]);
    }
}

void testArr() {
    int *arr = NULL;
    allocateSpace11(&arr);
    printArrayii(arr, 10);
}

void testArrStack1() {
    //堆上分配指针数组
    int **arr = malloc(sizeof(int *) * 5);//{int *,int *,int * ,int *, int*}

    for (int i = 0; i < 5; ++i) {
        arr[i] = malloc(sizeof(int));
        *(arr[i]) = i;
    }

    for (int j = 0; j < 5; ++j) {
        printf("index %d value %d\n", j, *arr[j]);
    }
}

void pointerChar() {
//    "abc" 的类型是char *

    //栈区指针数组
    char *p[] = {"aaa", "bbb", "ccc"};
    //堆区指针数组
    char **p3 = (char **) malloc(sizeof(char *) * 3);

    int i = 0;

    for (i = 0; i < 3; i++) {
        p3[i] = (char *) malloc(10 * sizeof(char));//char buf[10]
    }
}

#if 0

int main() {
    testArr();
//    testArrStack1();
}

#endif