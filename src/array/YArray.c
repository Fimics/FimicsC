//
// Created by pengju.li on 2019-06-14.
//

#include <stdio.h>
#include <strings.h>
#include "YArray.h"

#define MOHDHS 12


void init() {
    float candy[365];
    char code[12];
    int powers[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    //const 只读数组
    const int days[MOHDHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int days1[MOHDHS] = {31, 28, 31};
    const int days2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < MOHDHS; i++) {
        //printf("Month %2d has %2d days.\n",i+1,days[i]);
        /**
         * error: read-only variable is not assignable
         */
        //days[i]=44;
        //printf("Modify month %2d has %2d days.\n",i+1,days[i]);
    }

    //sizeof(days)//整个数组的大小
    // sizeof(days[0]) //数组中一个元素的大小 整个数组的大小/一个元素的大小=count

    int totolSize = sizeof(days);
    int perSize = sizeof(days[0]);
    int len = totolSize / perSize;

    printf("totalSize is %d, perSize is %d, len is %d\n", totolSize, perSize, len);

    //把arr[5]初始化为100
    int arr[6] = {[5]=100};

    printf("%s", "----------------------------------\n");
    int days3[] = {31, 28, [4]=301, 30, 31, [1]=29};
    for (int y = 0; y < MOHDHS; y++) {
        //printf("Month %d has %d days.\n",y+1,days3[y]);

    }

    printf("%s", "----------------------------------\n");
    int stuff[] = {1, [6]=23};//7 count
    /**
     * ----------------------------------
        index =0,value =1
        index =1,value =0
        index =2,value =0
        index =3,value =0
        index =4,value =0
        index =5,value =0
        index =6,value =4
        index =7,value =9
        index =8,value =10
     */
    int stuff1[] = {1, [6]=4, 9, 10};//
    for (int j = 0; j < sizeof(stuff1) / sizeof(stuff1[0]); ++j) {
        //printf("index =%d,value =%d\n" ,j,stuff1[j]);
    }

    int oxen[MOHDHS] = {2, 3, 4, 5};
    int yaks[MOHDHS];

    //yaks=oxen;
//    yaks[MOHDHS]=oxen[MOHDHS];//不起作用
//
//    for (int j = 0; j < MOHDHS ; ++j) {
//        printf("index =%d,value =%d\n" ,j,yaks[j]);
//    }


}

void testArray() {
//    init();
stringArray();

}