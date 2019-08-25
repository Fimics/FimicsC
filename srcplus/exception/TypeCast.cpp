//
// Created by lipengju on 2019-08-24.
//

#include <iostream>
using namespace std;

/**
 * 类型转换
 * 向上转是安全的，向下转是不安全的
 * 如果发生了多态，一定是安全的Animnal *animnal = new Cat();
 */


//---------------------------静态转换-------------------------

void staticCast(){
    char a ='a';
    double  d = static_cast<double>(a);
    cout<<"d= "<<d<<endl;
}

//父子之间转换
class BaseA{};
class ChildA:public BaseA{};
class Other{};

void testChild1(){
    BaseA *base=NULL;
    ChildA *child=NULL;

    //向下转型不安全
//    ChildA *child1 = static_cast<ChildA>(base);
//    BaseA *base1 = static_cast<BaseA>(child);
}

void typeCast(){
    staticCast();
}