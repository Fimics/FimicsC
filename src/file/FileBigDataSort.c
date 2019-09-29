//
// Created by lipnegju on 2019-07-01.
//

#include <time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define FILE_PATH "../resource/f.txt"
#define DATA_COUNT 10000

/**
 * 随机生生10000个数据，数据范围1-1000，写放到文件中，读取出来，进行从小到大的排序，再写入到文件中
 */

void bigDataWrite() {

    srand(time(NULL));
    FILE *fp = fopen(FILE_PATH, "w");
    if (!fp)
        return;

    for (int i = 0; i < DATA_COUNT; i++) {
        fprintf(fp, "%d\n", rand() % 1000 + 1);
    }

    fclose(fp);

}

void bigDataRead() {
    FILE *fp = fopen(FILE_PATH, "r");

    if (!fp)
        return;

    int *p = malloc(sizeof(int) * DATA_COUNT);
    for (int i = 0; i < DATA_COUNT; i++) {
        fscanf(fp, "%d\n", &p[i]);
        //printf("%d\n",p[i]);
    }

    for (int i = 0; i < DATA_COUNT - 1; i++) {
        for (int j = 0; j < DATA_COUNT - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

#if 0

int  main() {
// bigDataWrite();
    bigDataRead();
}

#endif