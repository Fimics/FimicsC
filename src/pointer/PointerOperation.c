//
// Created by lipnegju on 2019-06-23.
//
#include <printf.h>

#define SIZE 10

extern void printArray(int * arr);
extern void operation();

void printArray(int * arr){

    int i;
    for (i=0;i<=SIZE;i++){
        printf("index :%d --> value ；%d\n ",i,arr[i]);
    }

    printf("%s\n","-------------------------------------------");
}

void operation(){
    int arr[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int *p =arr;
    p++;
    *p =100; //arr[1]=100;
    printArray(arr);
    p=100; //野指针 不会出错，但非法操作会出错
    //*p=100; //非法操作野指针内存
    printArray(arr);
    p=&arr[9]; //p指向arr[9]
    *p=100; //arr[9]=100
    printArray(arr);
    p--;//p指向arr[9]
    *p=20;//arr[9]=20
    printArray(arr);
    p=&arr[0];//p指向arr
    *p+=100; //arr[0]=101
    printArray(arr);

    p+=100;
    int len = p-arr; //len=100? 400? ==> 100个 int Size
    printf("%d",len);
}

void operationArray(){
    int arr[SIZE]={1,2,3,4,5,6,7,8,9,10};
    int *p =arr;
    p=&arr[9];
    int len =p-arr; //len=9 间隔了9个
    printf("len %d",len);

    for (p=arr; p<=&arr[9];p++) {
        //printf("%d\n",*p);
        //printf("%d\n",p);
        printf("%d\n",p[0]);
    }


}



/**
 * 指针运算
 */
void pointerOperation(){
//operation();

operationArray();

}

