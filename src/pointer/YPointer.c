//
// Created by pengju.li on 2019-06-12.
//

#include <stdio.h>
#include <memory.h>
#include "YPointer.h"


/**
 *  & 后面跟一个变量名，&给出该变量的地址
 *  * 后面跟一个指针名，* ，给出存储在指针指向地址上的值
 */
void testPoint(){
    int a =5;
    int b =6;
    int *p =&a;
    printf("p%ld\n",p);
    p=&b;
    printf("*p %p\n",*p);
    printf("p%ld\n",p);
    int c =7;
    p=&c;
    printf("p%ld\n",p);
    printf("%p\n",*p);
    int cc = *p;
    printf("cc %d\n",cc);

    int names [5]={1,2,3,4,5};
    int *q;

    for (int i = 0; i <5; ++i) {
        q=&names[i];
        printf("q %ld\n",q);
        printf("*q %d\n",*q);
    }
}

/**
 * 声明指针时必须指定指针所指向变量的类型j
 * (*) p * 表示声明的变量是一个指针，指针是一个新类型，不是int类型， | 两个整数可以相乘，两个指针不可以
 * int *pi， pi是一个指针，*pi是int类型
 */
void declarePointer(){
    char address [] ="beijing";
   int * pi;
   char * pc;
   float  * pf,* pg;

   pc = &address;

   int addressLen = strlen(address);
    printf("p %ld\n",pc);
    printf("*p %d\n",*pc);
    for (int i = 0; i <addressLen ;i++) {
        printf("p %ld\n",pc);
        printf("*p %c\n",(char)*pc);
        pc++;
    }
}

void interChange(int * p,int * q){
     printf("before change %ld, %ld \n",p,q);
     int temp = *p;
     *p = *q;
     *q = temp;
    printf("after change %ld, %ld \n",p,q);
}

void swapWithPointer(){
    int x = 5;
    int y =10;
    printf("before swap x =%d, y =%d \n",x,y);
    interChange(&x,&y);
    printf("after swap x =%d, y =%d \n",x,y);
}


int diff(int x, int y){
    printf("diff &x =%ld, &y = %ld\n",&x,&y);
    int z ;
    x = x-y;
    return z;
}

/**
 * before testDiff &x =140732706547784, &y = 140732706547780
 * diff &x =140732706547740, &y = 140732706547736
 * after testDiff &x =140732706547784, &y = 140732706547780
 * @return
 */
int testDiff(){
    int x = 5,y =10;
    printf("before testDiff &x =%ld, &y = %ld\n",&x,&y);
    diff(x,y);
    printf("after testDiff &x =%ld, &y = %ld\n",&x,&y);
}


void change(int *p)
{
    *p = 4;
}


int testDiffPointer(){
    int a = 3;
    int *p = &a; //p的值为0x1111(假设)，*p的值为3
    change(p);
    printf("%x \n", p); //0x1111 指针变量的值不会被改变
    printf("%d \n", *p); //4 指针变量所指变量的值被改变
}

void testPointer(){
   //testPoint();
   //declarePointer();
   //swapWithPointer();
//   testDiff();
//    testDiffPointer();
//     pointerDefine();
//     wildNullPointer();
//      constTest ();
//  pointerAndArray();
//pointerOperation();
//pointerBubbleSort();
//    pointerStrchr();
     pointerMultilevel();
}