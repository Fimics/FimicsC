//
// Created by lipnegju on 2019-06-23.
//

#include <printf.h>
#include <string.h>

#define SIZE 10


void pointerArray1(){
    //数组名是数组的首地址，这是一个常量
    int arr[SIZE] ={0,20,30};
    printf("%p\n",arr);
    printf("%p\n",&arr[0]);
    printf("%d\n",arr[0]);

    arr[4]=40;

    // p是指向数组的指针
    //p=arr
    int * p = arr;

    //指针的降级操作
//    *p =100;
//    *(p+1)=200;
//    p[5]=500;//p[5]=*(p+5);

    *(p+1)=200; //p指向arr首地址，p+1时，p的值并没有发生变化，p+1相当于向后移一格
    p++; //p++ p的值发生了变化，已经不再指向arr的首地址了，而是指向了arr[1],所以*p=111改变的是arr[1]的值不是arr[0]的值
    *p=111;
    p++;
    *p=900;



    for (int i = 0; i <SIZE ; i++) {
        //*(p+i)  内存改变了1*sizeof(int)
        printf("index : %d ,value :%3d address: %p\n",i,*(p+i),p+i);
        printf("pi-------------------> index : %d ,value :%3d address: %p\n",i,arr[i],p+i);
    }
}

/**
 * 概念区别
 * 1.指针数组，数组里的元素是指针类型
 * 2.指向数组的指针，可以把数组当指针用
 */
void pointerArray(){
    int a=10;
    int b =20;
    int c = 30;

    int arr1[]={1,2,3};
    int * arr[]={&a,&b,&c};

    //arr[0]=&a;

    * arr[0]=100;

    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);

    //存储char *类型地址数组
    char  *arr2[] ={"hello","world"};
    int len = strlen(arr2[1]);
    printf("%c\n",*(arr2[1]+2));

}

/**
 * 指针与数组
 */

#if 0
int main(){
//   pointerArray1();
pointerArray();
}

#endif