//
// Created by lipnegju on 2019-07-26.
//

#include "StaticDemo.h"
#include <string>
#include <iostream>

using namespace std;

#if 0

//-------------------------静态成员-----------------------------

/**
 * 1.静态成员变量是属于某个类，所有对象共享，
 * 2.静态变量是在编译阶段分配空间，对象还创建时，就已经分配空间
 * 3.静态成员变量，在类内声明，类外进行初始化
 */

class Person{
public:

    Person(){}

    static int age;//静态成员变量，在类内声明，类外进行初始化

    /**
     * 1.静态成员函数不能访问非静态成员
     * 2.也是有权限的
     */
    static void func(){
        cout<<"age ="<<age<<"\n";
    }
private:
    static int sex; //私有静态变量不能在类外访问，但能在类外初始化
};

//在类外初始化
int Person::age=10;

void testStatic(){

        //通过对象访问static 变量
        Person p1;
        Person p2;
//      p1.size=20;

        p1.age=10;
        p2.age=20;

        cout<<"p1 age= "<< p1.age<<" p2 age "<<p2.age<<"\n";

        //通过类名访问

        int age = Person::age=90;
        cout<<"Person "<<age<<"\n";

        p1.func();
        p2.func();

}

#endif

void classMember(){
    //testStatic();
}