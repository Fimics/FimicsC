//
// Created by lipnegju on 2019-07-16.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * 指向函数的指针
 * 1.函数的名字编译完以后就是一个入口地址
 * 2.
 */

#if 0
//--------------------------------函数指针定义-------------------------------
void testFunc() {
    printf("hello world");
}

void testFuncPointer() {
//   printf("testFunc address %d\n",testFunc);
    int *funcAddress = (int *) testFunc;
    void (*myFunc)() =funcAddress;
    myFunc();
}


/**
 * 如何定义一个指向函数的指针？
 */

int testFunc1(int a, char b) {
    printf("method %s  a %d  b %c \n", "testFunc1", a, b);
}

void testFuncPointer1() {
    //1.定义函数类型，通过类型来定义函数指针 ，定义与使用时必须有一个*
    typedef int(FUN_TYPE)(int, char);
    FUN_TYPE *pFun = testFunc1;
//   pFun(2,'a');
//   (*pFun)(10,'b');
//   testFunc1(20,'c');

    //2.定义函数指针类型
    typedef int(*FUN_P)(int, char);
    FUN_P pFun1 = testFunc1;
//    pFun(2, 'a');
//    (*pFun)(10, 'b');
//    testFunc1(20, 'c');

//    pFun1=testFunc(); 函数指针应指向同类型

     //3.直接定义函数指针变量
     //把指针转换为函数指针类型写法
     int(*pFun3)(int , char)=(int (*)(int,char))NULL;
     int(*pFun2)(int ,char)=NULL;
     pFun2=testFunc1;
     pFun2(99,'p');
}

#endif

#if 1
//--------------------------------函数指针做函数参数-------------------------------

int addition(int x,int y){
    return x+y;
}

int subtraction(int x,int y){
    return x-y;
}

int multiplication(int x,int y){
    return x*y;
}

int division(int x,int y){
    if(y==0) return 0;
    return x/y;
}

void testOper(int (* pOper)(int,int)){
     int x =10;
     int y=20;
     int result = pOper(x,y);
     printf(" x %d y %d  result =%d\n",x,y,result);
}

//函数指针数组

void func0(){
    printf("func0\n");
}

void func1(){
    printf("func1\n");
}

void func2(){
    printf("func2\n");
}


void testFunPointerArray(){
    void(*funcArray[3])();
    funcArray[0]=func0;
    funcArray[1]=func1;
    funcArray[2]=func2;

    for (int i = 0; i <3 ; ++i) {
        funcArray[i]();
    }
}

/**
 * 函数指针做函数参数
 * 打印任意数组
 */
void printAnyArray(void * arr,int eleSize,int len,void(*print)(void *)){
    char *start =(char *)arr;
    for (int i = 0; i <len ; ++i) {
//        printf("%ld\n",start+i*eleSize);
        char * p = start+i*eleSize;
        print(p);
    }
}

void mYPrint(void *data){
    int * p =(int *)data;
    printf("%ld\n",*p);
}

struct Cat{
    char name[64];
    int age;
};

void mYPrintStruct(void *data){
    struct Cat * cat =(struct Cat *)data;
    printf("name %s age %d\n",cat->name,cat->age);
}


void testPrintAnyArray(){
    int arr []={1,2,3,4,5};
    //printAnyArray(arr, sizeof(int),5,mYPrint);
    struct Cat cats []={
            {"a",1},
            {"b",2},
            {"c",3},
            {"d",4},
            {"e",5},
    };

    printAnyArray(cats, sizeof(struct Cat),5,mYPrintStruct);

}

#endif

void iFunctionPointer() {
#if 0
    testFunc();
    testFuncPointer();
    testFuncPointer1();
    testOper(addition);
    testOper(subtraction);
    testOper(multiplication);
    testOper(division);
    testFunPointerArray();
#endif
    testPrintAnyArray();
}