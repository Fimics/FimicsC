//
// Created by pengju.li on 2019-08-01.
//

#include <iostream>
#include <gtest/gtest.h>
using  namespace std;

/**
 * 1.函数地址:函数名就是函数地址(后面不跟参数)
 */

void think(){
  cout<<"think 123"<<endl;
}

int pprint(int num){
    cout<<"pprint num "<<num<<endl;
    return 3;
}


void process(){
    int * address = (int *) think;
    void (*myFunc)() =reinterpret_cast<void (*)(void)>(address);
    myFunc();

    int (* mPrint)(int) =reinterpret_cast<int (*)(int)>((int *) pprint);
    mPrint(300);
}

TEST(testFunAddress,process){
    process();
    /**
    * 1.用(*pf) 替换函数名，pf就是这类函数的指针
    * 2.()优先级高于 * ， * pf(int)表示返回指针的函数，(*pf)(int)是指向函数的指针
    */
    double (*pf)(int);
}

