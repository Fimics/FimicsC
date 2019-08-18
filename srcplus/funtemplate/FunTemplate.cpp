//
// Created by lipengju on 2019-08-18.
//

#include <iostream>
using namespace std;

/**
 * 函数模板->泛型
 */


void swapInt(int &a,int &b){
    int tmp = a;
    a=b;
    b=tmp;
}

void swapDouble(double &a, double&b);

void testSwapInt(){
    int a=10;
    int b =20;
    swapInt(a,b);
    cout<<"a= "<<a<<"  b= "<<b<<endl;
}


/**
 * 类型参数化，泛型-模板
 * 1.告诉编译器，下面如果出现T不要报错，T是一个能用类型
 * @tparam T
 */
template <class T>

void mySwap(T &a,T &b){
    T tmp = a;
    a = b;
    b=tmp;
}


void testMySwap(){
    int a = 10;
    int b = 20;
    //自动类型推倒
    mySwap(a,b);
    cout<<"a= "<< a<<" b= "<<b<<endl;
}

void funTemplate(){
//     testSwapInt();
testMySwap();
}