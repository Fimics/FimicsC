//
// Created by lipengju on 2019-08-28.
//

#include<iostream>

using namespace std;

/**
 * 仿函数
 */

class MyPrint {
public:
    //重载(),
    void operator()(int num) {
        cout << "num " << num << endl;
        count++;
    }

    int count = 0;
};

void MyPrint2(int num) {
    cout << "num " << num << endl;
}

void testFunctor01() {
    //MyPrint是一个类 ，而不是函数
    MyPrint myPrint;
    myPrint(111);

    //MyPrint2(111);

    MyPrint()(1000);
}

//函数对象超出普通函数概念，内部可以保存状态
void testFunctor02() {
    MyPrint myPrint;
    myPrint(111);
    myPrint(111);
    myPrint(111);
    myPrint(111);
    cout << "myPrint使用次数：" << myPrint.count << endl;
}

//函数对象作为参数
void doPrint(MyPrint print, int num) {
    print(num);
}

void testFunctor03() {
    doPrint(MyPrint(), 20);
}

void functor() {
}