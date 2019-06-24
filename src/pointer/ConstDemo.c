//
// Created by lipnegju on 2019-06-23.
//


#include <printf.h>
#define SIZE 20 //对应的内存空间不允许改变其值

void constTest(){

    //这种方式不安全，可以通过指针修改
    const int a =10;
    int * p = &a;
    *p = 100;
    printf("%d\n",*p);


    int b =20;
    int c=30;
    //如果const修饰 int * 类型，不能修改指针变量指向内存地址的值,但可以改变指针指向的地址
    const int * q;
    q = &b;
    // *q =200;
    q=&c;
    printf("%d\n",*q);


    int d =10;
    int e =20;
    //如果const修饰 w(变量) 不能修改指针指向的地址，但可以修改指针指向内存地址的值
    int * const w = &d;
    *w=100;
//    w=&e;
    printf("%d",*w);

    int i=10;
    int j=20;
    //const 修饰指针类型也修饰指针变量，那么不能改变指针指向的地址，也不能改变指针指向的值
    const  int * const n = &i;
//    n=&j;
//      *n=j;
    printf("%d",*n);




}