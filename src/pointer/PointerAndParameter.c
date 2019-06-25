//
// Created by lipnegju on 2019-06-25.
//

#include <printf.h>
#include <string.h>

/**
 * 值传递：实参的值伟给形参，
 * @param a
 * @param b
 */
void swap1(int a , int b){
    int temp =a;
    a=b;
    b=temp;
    printf("a = %d b=%d\n",a,b);
}


void swap2(int * a , int * b){
    int temp =*a;
    *a=*b;
    *b=temp;
    printf("a = %d b=%d\n",*a,*b);
}

void printArray1(int * arr, int len){

    //函数参数中如有数组，都会转化为指针
    for (int i = 0; i < len ; i++) {
        printf("index is %d value is %d\n",i,arr[i]);
    }
}

/**
 * 1.数组作为函数参数可退化为指针
 * 2.在传递数组时需要加上数组的个数
 * @param arr
 */
void printCharArray(char * arr){
    /**
     * 两种方式可以求出字符串长度
     */

    int len = strlen(arr);

//    for (int i = 0; i <len ; i++) {
//        printf("index is %d value is %c\n",i,arr[i]);
//    }

    int i=0;
    while (arr[i]!='\0'){
        printf("index is %d value is %c\n",i,arr[i]);
        i++;
    }
}

void pointerAndParameter(){
 int a =5,b=10;
 //swap1(a,b);
 swap2(&a,&b);
 printf("params a = %d b=%d\n",a,b);

    //  int arr [10] ={1,2,3,4,5,6,7,8,9,10};
//  int len = sizeof(arr)/ sizeof(arr[0]);
//  printArray1(arr,len);

    char arr[] = "hello world";//字符串
    char arr1 ={"a",'b','c'};//字符数组
    printCharArray(arr);
}