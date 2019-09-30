//
// Created by lipnegju on 2019-07-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

/**
 * void calloc(size_t nmemb,size_t size)
 * 功能:
 *   在内存动态存储区中分配nmemb块长度为size字节的连续区域，calloc自动把分配的内存设置为0
 * 参数:
 *    nmemb;块数
 *    size：每块大小
 */

/**
 * relloc(void *ptr,size_t size)
 * 功能:
 *    重新分配用malloc或calloc函数在堆中分配内存空间的大小
 *    relloc不会自动清理增加的内存，需要手动清理，如果指定的地址后面有连续的空间那么就会在已有地址基础上增加内存
 *    如果指定的地址后面没有空间，那么relloc会重新分配新的连续内存，把旧的内存值拷贝到新的内存，同时释放旧内存
 * 参数:
 *  *psr 为之前用malloc或calloc分配的内存地址，如果此参数为NULL, realloc与malloc功能一样
 *
 */

void testCalloc() {
    int *p = calloc(SIZE, sizeof(int));
    for (int i = 0; i < SIZE; ++i) {
        p[i] = i;
    }

    for (int j = 0; j < SIZE; ++j) {
        printf("index- %d value- %d\n", j, p[j]);
    }

    if (p != NULL) {
        free(p);
        p = NULL;
    }

}

void testRelloc() {
    int *p = malloc(sizeof(int) * 10);
    int *q = realloc(p, 200);

}

#if 0

int main() {
    testCalloc();
    testRelloc();
}

#endif