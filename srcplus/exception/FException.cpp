//
// Created by lipengju on 2019-08-24.
//

#include <iostream>
#include <stdexcept>
#include <gtest/gtest.h>
using namespace std;

/**
 * 1.catch(...) 代表其它的异常类型
 * 2.如果不想处理异常，可以继续向上抛出 throw
 * 3.如果没有任何处理异常的地方，那么成员调用terminate函数，中断程序
 *
 * 解旋
 * 1.从 try开始到 throw之间所有栈上的对象，都会被释放，这个过程叫解旋
 * 2.栈上的对象与析构相反
 */


int divTry(int a,int b){

    if(b==0){
        throw -1;
    }
    return a/b;
}

TEST(try,catchException){
    try {
        divTry(1,0);
    }catch(int){
        cout<<"exception"<<endl;
    }catch(double){
        cout<<"exception"<<endl;
    } catch(...){
        cout<<"other"<<endl;
    }
}

/**
 * 异常接口声明
 * 1.如果想抛出特定类型异常，可以用异常接口声明，只能抛出声明的类型，
 */

void func2(int a,int b) throw(int){
    throw -1;
};

//异常的生命周期
class MyException{
public:
    MyException() {}

    virtual ~MyException() {
    }
};

//class OutOfRangeException:public exception{
//public:
//
//    OutOfRangeException(string errorinfo) {
//        this->errorInfo=errorinfo;
//    }
//
//    ~OutOfRangeException() override {
//
//    }
//
//    virtual char *what() const  {
//
//        return const_cast<char *>(this->errorInfo.c_str());
//    }
//
//    string errorInfo;
//};

void testFun2(){
    try {
       func2(2,1);
    }catch(int){
        cout<<"func2 exception"<<endl;
    }

//    throw MyException(); //自定义异常
//      throw out_of_range("数组越界"); //使用系统异常
}