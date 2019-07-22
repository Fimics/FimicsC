//
// Created by lipnegju on 2019-07-22.
//

#include <iostream>
#include "Basic.h"

using namespace std;

int num =200;

void  A::a() {
    cout<<"namespace A->a()\n";
}

void B::a() {
    cout<<"namespace B->a()\n";
}

void print(){
    int num =100;

//    cout << num<< endl;
      cout<<num <<"\n";
      //双冒号->全局作用域
      cout<<::num <<"\n";//
}


void basic(){
#if 0
    print();
#endif
    A::a();
    B::a();
}