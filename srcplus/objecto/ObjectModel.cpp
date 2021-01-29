//
// Created by lipnegju on 2019-07-27.
//

#include <iostream>
#include <gtest/gtest.h>
using namespace std;


//----------------------------对象模型  |this -------------------------------
class Person{

public:

    Person(){
        this->age=10;
    }

    Person(Person & person){
    }

    const string name;
    mutable int age1; //加了mutable可以在常函数中被修改
    int age; //非静态成员对象属于类身上
    int getAge(){ //非静态成员函数不属于对象身上 //编译器会偷偷的加一个 Person * this指针
//        return age;
        return  1;
    }

    static int sex;//静态成员对象不属于对象身上

    static int getSex(){ //静态成员函数不属于对象身上的
        return sex;
    }

    void show(){
//        this->age=20;
        if(NULL==this)
            return;
        cout<<"show person\n";
    }

    /**
     * 1.常函数，不允许修改指针指向的值
     * 2.加了mutable可以在常函数中被修改
     */
    void showInfo() const {
//        this->age=10;
          this->age1=20;
          cout<<"show info\n";
    }
};

TEST(常对象与函数,mutable){
    /**
     * 空类的大小为1 每个实例的对象都有一个独一无二的地址，char 维护这个地址
     */
    cout<<"Person size of ="<< sizeof(Person);

    //空指针访问成员函数

    Person * person = NULL;
    person->show();
    person->getAge();
    /**
     * 1.常对象不允许修改对象的值
     * 2.不可以调用普通的成员函数
     * 3.可以调用常函数
     */
    const Person p1;
    cout<<p1.age<<"\n";
//    p1.show(); 不可以调用普通的成员函数
      p1.showInfo();
}