//
// Created by lipengju on 2019-08-18.
//

#include <iostream>
#include <string>

using namespace std;

/**
 * 函数模板->泛型
 */


void swapInt(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapDouble(double &a, double &b);

void testSwapInt() {
    int a = 10;
    int b = 20;
    swapInt(a, b);
    cout << "a= " << a << "  b= " << b << endl;
}


/**
 * 类型参数化，泛型-模板
 * 1.告诉编译器，下面如果出现T不要报错，T是一个能用类型
 * @tparam T
 */
template<class T>


void mySwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void mySwap2() {};

void testMySwap() {
    int a = 10;
    int b = 20;
    char c = 'c';
    //自动类型推倒
    mySwap(a, b);
//    mySwap(a,c); 推倒不出类型，所以报错不能运行

    //显式指定类型
    mySwap<int>(a, b);

    //模板必须指定出T才能使用
//    mySwap2(); 不能运行
    cout << "a= " << a << " b= " << b << endl;
}

//----------------------------通用数组排序------------------------------------

/**
 * 从大到小，选择排序
 */

template<class T>
void tSwap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
void arraySort(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        int max = i;

        for (int j = i + 1; j < len; j++) {
            if (arr[max] < arr[j]) {
                //交换下标
                max = j;
            }
        }

        if (max != i) {
            //交换数据
            tSwap(arr[max], arr[i]);
        }
    }
}

template<class T>
void printArr(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << endl;
    }
}

void testArraySort() {
    int arr[] = {4, 9, 1, 3, 6, 8, 0};
    int len = sizeof(arr) / sizeof(int);
    arraySort(arr, len);
    printArr(arr, len);
}

//------------------------------模板局限性-------------------------------------

class Person {


public:
    Person(string name, int age) {
        this->age = age;
        this->name = name;
    }

    string name;
    int age;
};

template<class T>

bool myCompare(T &a, T &b) {
//    if (a == b) return true;
    return false;
}

////通过具体化自定义类型
//
//template <> bool myPersonCompare<Person>(Person &a ,Person &b){
//    if(a.age==b.age) return true;
//    return false;
//}



void testMyCompare() {
//    int a=10;
//    int b =20;
//    bool  result = myCompare(a,b);
//    cout<<result<<endl;

    Person p1("tom", 2);
    Person p2("tom2", 2);

    bool result1 = myCompare(p1, p2);
}

//------------------------类模板基本使用-------------------------

template<class T, class K=int>
class Strdent {
public:

    Strdent(T name, K age) {
        this->name = name;
        this->age = age;
    }

    T name;
    K age;

    /**
     *
     */
    void showInfo() {
        cout << "name->" << this->name << " age-> " << this->age << endl;
    }
};


void testClassTemplate() {
    //类模板不支持自动类型推倒
//    Strdent p1("zhangsan",100);


    Strdent<string, int> s("张三", 100);
    s.showInfo();
}

//---------------------------------成员函数创建时机------------

class Person1 {
public:
    void showPerson1() {
        cout << "showPerson1\n";
    }
};


class Person2 {
public:
    void showPerson2() {
        cout << "showPerson1\n";
    }
};

template<class T>
class myClass {
public:
    T obj;

    void func1() {
        obj.showPerson1();
    }

    void func2() {
        obj.showPerson2();
    }
};

void testPerson1() {

    myClass<Person1> m;
    m.func1();
}

//---------------------------------类模板做函数参数-----------------------------------
template<class T, class K=int>
class Dog {
public:

    Dog(T name, K age) {
        this->name = name;
        this->age = age;
    }

    T name;
    K age;

    /**
     *
     */
    void showInfo() {
        cout << "name->" << this->name << " age-> " << this->age << endl;
    }
};

//指定传入类型
void doWork(Dog<string, int> &p) {
    p.showInfo();
}

//参数模板
template<class T1, class T2>
void doWork1(Dog<T1, T2> &p) {
    p.showInfo();
}

//-------------------------------模板与继承----------------------------

template<class T>
class Base {
public:
    T age;
};

/**
 * Child继承base类时，必须告诉base中T的类型，否则T无法分配内存
 */
class Child : public Base<int> {

};

template<class T1, class T2>
class Child2 : public Base<T2> {
public:
    T1 age;
};

//----------------------类内，类外实现类模板--------------
//TODO

template<class T1, class T2>
class Cat {
public:
    Cat(T1 name, T2 age) {
      this->name=name;
      this->age=age;
    }

    T1 name;
    T2 age;
};


void testChild2() {
    //T1的类型是int,T2的类型是double
    Child2<int, double> child2;
}

void funTemplate() {
//     testSwapInt();
//testMySwap();
// testArraySort();
//    testMyCompare();
//    testClassTemplate();
//      testPerson1();
}