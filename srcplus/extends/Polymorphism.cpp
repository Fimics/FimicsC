//
// Created by lipnegju on 2019-08-02.
//
#include <iostream>
using namespace std;

/**
 * 1.静态多态就是函数重载
 * 2.静态多态和动态多态的区别就是函数地址的早绑定(静态联编)还是晚绑定(动态联编)
 */

class Animal{
public:
    void eat(){
        cout<<"animal eat..."<<endl;
    }
};

class Cat :public Animal{
public:
    void eat(){
        cout<<"cat eat..."<<endl;
    }57038833
};

void testEat(Animal & animal){
    animal.eat();
}

void polymorphism(){
    Cat cat ;
    testEat(cat);
}