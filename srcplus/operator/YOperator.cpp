//
// Created by lipnegju on 2019-07-28.
//

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

class MyOperator {
public:
    int a;
    int b;

    MyOperator() {}

    MyOperator(int a, int b) : a(a), b(b) {}

    //+号运算符重载，成员函数
    MyOperator operator+(MyOperator &myOperator) {
        MyOperator tmp;
        tmp.a = this->a + myOperator.a;
        tmp.b = this->b + myOperator.b;
        return tmp;
    };

    //前置++
    MyOperator &operator++() {
        this->a++;
        return *this;
    }

    //后置++ 用占位参数区分前置后置 后置++每次都创建临时数据，多次调用操作的不是同一个值，所以返回值
    MyOperator operator++(int) {

        MyOperator tmp = *this;
        this->a++;
        return tmp;
    }

};

class Person {
public:
    Person(int a) {
        age = a;
    };

    ~Person() {
        cout << "destroy Person\n";
    }

    int showAge() {
        cout << "person age = " << this->age << "\n";
        return this->age;
    }

private:
    int age;
};

/**
 * 智能指针,用来托管自定义类型的对象，让对象进行自动的释放
 * 1.Person类有showage成员函数
 * 2.如果是new出来的Person对象，程序员就要自觉的去释放 delete
 * 3.有了智能指针，可以让智能指针托管，自动释放被托管的对象
 * 4.
 */
class SmartPointer {
public:
    SmartPointer(Person *person) {
        this->person = person;
    }

    //重载->
    Person *operator->() {
        return this->person;
    }

    //重载*
    Person &operator*() {
        return *this->person;
    }

    ~SmartPointer() {
        cout << "destroy SmartPointer" << endl;
        if (this->person != NULL) {
            delete person;
            this->person = NULL;
        }
    }

private:
    Person *person;
};

/**
 * =赋值运算符重载
 * 1.一个类默认创建
 *    1.1 默认构造函数
 *    1.2 析构函数
 *    1.3 拷贝构造
 *    1.4 =号运算符重载 进行简单的值传递(拷贝)
 */

class Dog {
    char *name;
public:
    Dog(char *name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    //=赋值运算符重载  赋值时不重载=会出现深拷贝，浅拷贝问题，会多次释放同一块内存
    Dog &operator=(const Dog &dog) {
        //如果原来的堆区已经有内存先释放
        if (this->name != NULL) {
            delete[] this->name;
            this->name = NULL;
        }
        this->name = new char[strlen(dog.name) + 1];
        strcpy(this->name, dog.name);
        return *this;
    }

    char *getName() {
        return name;
    }

    virtual ~Dog() {
        if (this->name != NULL) {
            delete[] this->name;
            this->name = NULL;
        }
    }
};

/**
 * 函数调用运算符()重载
 */

class MyPrint {
public:
    void operator()(string text) {
        cout << "MyPrint() " << text << endl;
    }
};

class MyAdd {
public:
    int operator()(int x, int y) {
        return x + y;
    }
};

//int main() {
//
//
//    MyOperator myOperator(1, 1);
//    MyOperator myOperator1(2, 2);
//
//    MyOperator myOperator2 = myOperator + myOperator1;
//    cout << "m2 a =" << myOperator2.a << " m2 b=" << myOperator2.b << "\n";
//
//    //智能指针
//    Person *person = new Person(3);
//    SmartPointer sp(person);
//    //int age = sp->showAge();// sp->->showAge() 编译器优化了写法
//
//    (*sp).showAge();
//
//    //=运算符号重载
//    Person p1(2);
//    Person p2 = p1;
//    cout << "p2 age " << p2.showAge();
//
//    //=赋值运算符重载
//    Dog dog1("AAA");
//    Dog dog2("BBB");
//    Dog dog3("CCC");
//    dog1 = dog2 = dog3;
//    cout << "dog1 name is : " << dog2.getName() << endl;
//    int a = 10;
//    int b = 20;
//    int c;
//    c = a = b;
//    cout << " a,b ,c " << a << " , " << b << " , " << c;
//
//
//    MyPrint myPrint;
//    myPrint("hello");//仿函数，不是函数调用
//
//    MyAdd myAdd;
//    int result = myAdd(1, 2);
//    cout << "result = " << result << endl;
//    cout << "Myadd()" << MyAdd()(2, 3) << endl;//通过匿名对象调用

//}