//
// Created by lipnegju on 2019-07-16.

/**
 * 指向函数的指针
 * 1.函数的名字编译完以后就是一个入口地址
 * 2.
 */


void testFunc(){
    printf("hello world");
}

void testFuncPointer(){
//   printf("testFunc address %d\n",address);
   int *funcAddress =(int *)testFunc;
   void(*myFunc)()=funcAddress;
   myFunc();
}

/**
 * 如何定义一个指向函数的指针？
 */

void iFunctionPointer(){
//   testFunc();
     testFuncPointer();
}