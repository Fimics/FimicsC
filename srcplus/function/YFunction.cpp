//
// Created by lipnegju on 2019-07-25.
//

#include <iostream>
#include "FunctionPointer.h"
using namespace std;

#include "YFunction.h"
#include "ExternC.h"

#if 0
//------------------------宏函数的缺点----------------------------
/**
 * 宏函数的缺点
 * 1.宏函数没有作用域
 * 2.各种加括号
 */
#define  add(x,y) x+y
#define  add1(x,y) （（x）+（y））

void testDefineFunction(){
    int result =add(1,2);
    cout<<"result "<<result<<"\n";

    int b = add(1,2)*3; //实际输出7 ，这种情况可以用add1() 加小括号处理
    cout<<"b ="<<b<<"\n";
}

#endif

#if 0
//------------------------内联函数----------------------------

//类内部的成员函数默认为inline函数
inline void funa();//内联函数声明
inline void funa(){// 如函数实现没有加inline 那么这个函数任然不是内联函数

}

/**
 * 内联函数与宏函数
 * 1.内联函数与常规函数一样，也是按值传递
 * 2.宏函数是通过文本替换实现的
 * #definie SOURCE(x) x*x;
 * a=SOURCE(4.5+7.5)=4.5+7.5*4.5+7.5
 *
 * 内联函数与编译器  以下情况编译器可能不会把函数进行内联编译
 * 1.不能存在任何形式的循环语句
 * 2.不能存在过多的条件判断语句
 * 3.函数体不能过于庞大
 * 4.不能对函数进行取地址操作
 * //内联仅仅只是给编译器一个建议，编译器不一定会接受这种建议，如果你没有把函数声明为内联函数，那么编译器也可能瓜皮函数内联编译
 * //一个好的编译器会内联小的，简单的函数
 */

/**
 * 函数的默认参数
 * 1.如果某个位置有了默认参数，那么从这个位置往后的参数都要有默认参数
 * @param a
 * @param b
 */
void testFuna(int a=10,int b=2){}

/**
 * 函数占位参数
 * 1.如果有了占位参数，函数调用时候必须要提供这个参数，但是用不到参数
 * 2.占位参数没什么大用途，只有后面重载++号才有一点点用
 * 3.占位参数可以有默认值
 */
void testFunb(int a ,int =1){}

/**
 * 函数重载
 * @param a
 */
void testFunOverload(){}
void testFunOverload(int a){}
void testFunOverload(float a){}

/**
 * 函数重载遇到默认参数，要避免二义性
 * @param a
 */
void testFunOverload(char a){}
int testFunOverload(char a,int c=10){}

//引用作为函数参数重载
void testOverLoad(int &a){}//引用必须要引用合法的内存空间
void testOverload(const int &a){}//const也可以作为重载的条件

/**
 * 函数重载原理
 * 1.编译器内部把函数名改了
 */

#endif


#if 1
//------------------------extern c 分析----------------------------

#endif

void yFunction(){

#if 0
    testDefineFunction();
#endif
   // externC();
   functionPointer();

}