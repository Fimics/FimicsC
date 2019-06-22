//
// Created by lipnegju on 2019-06-23.
//

#include <stdio.h>


void define(){
    int a =5;
    //指针是一种数据类型，p是指针类型变量，用来指向一个变量地址
    // 在32位系统中所有指针类型的大小都是4位，64位系统中都是8位 都是无符号整型
    int * p =&a; // int * 是数据类型， p是变量
    int * *q =&p;

    printf("*p %d\n",*p);
    printf("p %ld\n",p);

    printf("q %ld\n",q);
    printf("*q %ld\n",*q);
    printf("**q %d\n",**q);

    //通过指针修改变量的值
    *p =20;
    printf("a%d\n",a);
    printf("*p%d\n",*p);

    //sizeof()指针类型在内存中的大小
    printf("sizeof(p) %d\n", sizeof(p));
    printf("sizeof(int *) %d\n", sizeof(int *));

}

void pointerDefine(){
    define();
}