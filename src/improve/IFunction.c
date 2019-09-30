//
// Created by lipnegju on 2019-07-08.
//

#include <stdio.h>

/**
 * 1.宏函数，它不是一个函数，但使用起来像一个函数
 * 2.宏函数在一定场景下比函数效率高
 */
#define  MYADD(x, y) (x+y)

/**
 * 函数的调用流程与开销
 * 1.为什么函数参数列表不能颠倒-->涉及到函数入栈顺序问题
 * 2.cdecl惯例是什么？
 * 3.
 */



/**
 * 这个才是函数
 * 1.返回值
 * 2.参数
 * 3.函数体
 * @param x
 * @param y
 * @return
 */
int add(int x,int y){
    return x+y;
}


void macroFunction() {
   int a =10;
   int b=20;

   printf("a+b=%d\n",MYADD(a,b));
}


#if 0

int main() {
    macroFunction();
}

#endif