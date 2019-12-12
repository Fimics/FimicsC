//
// Created by pengju.li on 2019-06-14.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#define MONTHS 12
#define YEARS   5
#define SIZE 4
#define SIZE_SUM 10

//-------------------------------arrayInit---------------------------------------
void arrayInit() {
    float candy[365];
    char code[12];
    int powers[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    //const 只读数组
    const int days[MONTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int days1[MONTHS] = {31, 28, 31};
    const int days2[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < MONTHS; i++) {
        printf("Month %2d has %2d days.\n",i+1,days[i]);
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
    for (int y = 0; y < MONTHS; y++) {
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

    int oxen[MONTHS] = {2, 3, 4, 5};
    int yaks[MONTHS];

    //yaks=oxen;
//    yaks[MOHDHS]=oxen[MOHDHS];//不起作用
//
//    for (int j = 0; j < MOHDHS ; ++j) {
//        printf("index =%d,value =%d\n" ,j,yaks[j]);
//    }


}


//-------------------------------array2d---------------------------------------

void initArray2D() {
    // initializing rainfall data for 2010 - 2014
    const float rain[YEARS][MONTHS] =
            {
                    {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
                    {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
                    {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
                    {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
                    {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
            };
    int year, month;
    float subtot, total;

    printf(" YEAR    RAINFALL  (inches)\n");
    for (year = 0, total = 0; year < YEARS; year++) {             // for each year, sum rainfall for each month
        for (month = 0, subtot = 0; month < MONTHS; month++)
            subtot += rain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot; // total for all years
    }
    printf("\nThe yearly average is %.1f inches.\n\n",
           total / YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");

    for (month = 0; month < MONTHS; month++) {             // for each month, sum rainfall over years
        for (year = 0, subtot = 0; year < YEARS; year++)
            subtot += rain[year][month];
        printf("%4.1f ", subtot / YEARS);
    }
    printf("\n");

}

//-------------------------------指针和数组---------------------------------------

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

    /**
     * uj
     * *（dates+2）dates第三个元素
     * *dates+2 第一个元素的值加2
     */

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

void testSump() {
    int marbles[SIZE_SUM] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
    long answer;

    answer = sump(marbles, marbles + SIZE_SUM);
    printf("The total number of marbles is %ld.\n", answer);
}

//-------------------------------testRand---------------------------------------
void testRand(){

    srand((unsigned int)time(NULL));

    for (int i = 0; i <100 ; i++) {
        int randNum = rand()%10+50;
        printf("randNum is %d\n",randNum);

    }

}

//-------------------------------stringArray---------------------------------------

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


#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, int ar[rows][cols]);

void testSum2d() {
    int i, j;
    int rs = 3;
    int cs = 10;
    int junk[ROWS][COLS] = {
            {2,  4,  6, 8},
            {3,  5,  7, 9},
            {12, 10, 8, 6}
    };

    int morejunk[ROWS - 1][COLS + 2] = {
            {20, 30, 40, 50, 60, 70},
            {5,  6,  7,  8,  9,  10}
    };

    int varr[rs][cs];  // VLA

    for (i = 0; i < rs; i++)
        for (j = 0; j < cs; j++)
            varr[i][j] = i * j + j;

    printf("3x5 array\n");
    printf("Sum of all elements = %d\n",
           sum2d(ROWS, COLS, junk));

    printf("2x6 array\n");
    printf("Sum of all elements = %d\n",
           sum2d(ROWS - 1, COLS + 2, morejunk));

    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n",
           sum2d(rs, cs, varr));

}

// function with a VLA parameter
int sum2d(int rows, int cols, int ar[rows][cols]) {
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            tot += ar[r][c];

    return tot;
}


#if 1
int main(){
//  arrayInit();
//initArray2D();
//    pointAdd();
    months();
}
#endif