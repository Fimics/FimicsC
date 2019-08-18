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
    //静态联编
//    void eat(){
//        cout<<"animal eat..."<<endl;
//    }

   //动态联编
   virtual void eat(){
        cout<<"animal eat..."<<endl;
    }
};

class Cat :public Animal{
public:
    void eat(){
        cout<<"cat eat..."<<endl;
    }
};

/**
 * 1.静态联编 outupt ->animal eat...
 * 调用testEat时，参数的地址已经绑定好了(早绑定，静态联编，编译阶段就确定好了地址)
 * 2.如果想调用cat的eat,不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址(动态联编)
 *  写法eat()方法改为虚函数，在父类上声名虚函数
 */
void testEat(Animal & animal){
    animal.eat();
}

void polymorphism(){
    //如果发生了继承关系，编译器允许进行类型转换
    Cat cat ;
    testEat(cat);
}