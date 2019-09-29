//
// Created by lipnegju on 2019-06-28.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 10

/**
 * memset 内存重置
 */
void testMemset() {
    int *p = malloc(sizeof(int) * MAX);

    /**
     * 参数：
     * p:
     * 0: 每个字节被重置后的值，只能重置为0 ，因为是重设置的每个字节
     * len->字节大小
     */
    memset(p, 1, sizeof(int) * MAX);

    for (int i = 0; i < MAX; i++) {
        printf("index = %d value =%d\n", i, p[i]);
    }

    free(p);

    /**
     * 每个字节者是'A'=65
     */
    char *q = malloc(sizeof(char) * MAX);
    memset(q, 65, 10);
    printf("%s\n", q);
    free(q);

    /**
     * 重置一个栈区数组
     */
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memset(arr, 0, 40);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

}

/**
 * memcpy 内存拷贝，堆区和栈区可以相互拷贝
 */
void testMemcpy() {

    int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = malloc(sizeof(int) * MAX);
    memcpy(p, arr, sizeof(int) * MAX);

    for (int i = 0; i < MAX; i++) {
        printf("value =%d\n", p[i]);
    }

    free(p);

    /**
     * 如果拷贝的目标地址和源地址重叠，会同时出现读写一个数据，会发生异常
     */
//    memcpy(&arr[2],arr,20);

    char arr1[] = {'h', 'e', 'l', 'l', 'o'};
    char *q = malloc(100);
//     memset(q,0,100);
    strcpy(q, arr1);//拷贝'\0'之前的内容
    printf(" q-> %s", q);
}

/**
 * memMove 出现内存重叠时用这个，保证不出错
 * memcmp 比较
 */
void testMemMove() {
    int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    memmove(&arr[2], arr, 20);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    int arr1[5] = {1, 2, 3, 4, 5};

    int cmp = memcmp(arr, arr1, 4);//返回 0 ，前一个元素相同
    printf("cmp =%d\n", cmp);
}

/**
 * memcmp
 */
void testMemCmp() {
//int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //int arr2[5] = { 1,2,3,4 };

    //int val = memcmp(arr1, arr2, 20);
    //if (!memcmp(arr1, arr2, 8))
    //{
    //	printf("前两个数组元素内容相同");
    //}
    //printf("%d\n", val);

    //int * p1 = malloc(sizeof(int) * 10);
    //char * p2 = malloc(sizeof(char) * 40);

    //memcpy(p1, "hello", 6);
    //memcpy(p2, "hello", 6);
    //if (!memcmp(p1, p2, 6))
    //{
    //	printf("内容相同\n");
    //}
    //else
    //{
    //	printf("内容不相同\n");

    //}

    int a = 0xffff;
    char b = 0xffff;
    //printf("%d\n", b);
    if (!memcmp(&a, &b, 1)) {
        printf("内容相同\n");
    } else {
        printf("内容不相同\n");

    }

    //free(p1);
    //free(p2);
}

#if 0

int main() {
    testMemset();
//    testMemcpy();
//    testMemMove();
//    testMemCmp();
}

#endif