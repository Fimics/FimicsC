//
// Created by lipnegju on 2019-06-15.
//

#include <stdio.h>
#include  "Array.h"

#define SIZE 4
#define SIZE_SUM 10
#define MONTHS 12

/**
 * 数组名是数组首元素的地址，如a是一数组 ，a ==&a[0]
 */


void pointAdd() {
    short dates[SIZE];
    short *pti;
    short index;
    double bills[SIZE];
    double *ptf;

    pti = dates;
    ptf = bills;

    printf("%23s %15s\n", "short", "double");

    for (index = 0; index < SIZE; index++) {
        printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
    }

}

void months() {
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;

    for (int index = 0; index < MONTHS; index++) {
        printf("Month %2d has %d days.\n", index + 1, *(days + index));
    }
}

int sumDays(int days[]) {

//    int totalSize = sizeof(days);
//    int perSize = sizeof(days);
//    int len = totalSize/perSize;
//    int sum;
//
//    for (int i = 0; i <len ; i++) {
//        sum+=days[i];
//    }
//    return sum;
}

int sumArr1(int ar[], int n)     // how big an array?
{
    int i;
    int total = 0;

    for (i = 0; i < n; i++) {
        total += ar[i];
    }
    printf("The size of ar is %zd bytes.\n", sizeof ar);

    return total;
}

void testSumArr1() {
    int marbles[SIZE_SUM] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sumArr1(marbles, SIZE_SUM);
    printf("The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %zd bytes.\n",
           sizeof marbles);
}

/* use pointer arithmetic   */
int sump(int *start, int *end) {
    int total = 0;

    while (start < end) {
        total += *start; // add value to total
        start++;         // advance pointer to next element
    }

    return total;
}

void testSump(){
    int marbles[SIZE_SUM] = {20,10,5,39,4,16,19,26,31,20};
    long answer;

    answer = sump(marbles, marbles + SIZE_SUM);
    printf("The total number of marbles is %ld.\n", answer);
}


void testArrayAndPointer() {
//    testSumArr1();
testSump();
}