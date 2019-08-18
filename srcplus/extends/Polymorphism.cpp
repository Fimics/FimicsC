//
// Created by lipnegju on 2019-08-02.
//
#include <iostream>

using namespace std;

/**
 * 1.静态多态就是函数重载
 * 2.静态多态和动态多态的区别就是函数地址的早绑定(静态联编)还是晚绑定(动态联编)
 */

class Animal {
public:
    //静态联编
//    void eat(){
//        cout<<"animal eat..."<<endl;
//    }

    /**
     * 动态联编
     *  原理:
     *   1.vfptr内部有这么个指针 virtual function poiner(虚函数指针) 指向虚函数表
     *   2.子类在调用构造函数时，将所有的虚函数表指针都指向自己的虚函数表，这个操作我们是看不到的
     *   3.子类的虚函数表会把子类内部的虚函数表覆盖(重写)，但父类的虚函数表不受影响
     *
     * @return
     */

    virtual void eat() {
        cout << "animal eat..." << endl;
    }
    // 普通的析构是不会调用子类的析构函数的，所以可能会导致子类释放不干净,用虚析构来解决
//    ~Animal(){
//        cout<<"~Animal";
//    }

    /**
     * 纯虚析构
     * 1.需要声明还需要实现，类内声明，类外实现
     * 2.如果类中出现了纯虚析构，这个类也是抽象函数
     */

    virtual ~Animal()=0;
//    virtual ~Animal(){
//        cout<<"~Animal";
//    }
};

Animal::~Animal() {

}

class Cat : public Animal {
public:
    char *name;

    Cat(char *name) {
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    ~Cat() {
        cout<<"~Cat()";
        if(this->name!=NULL){
            delete [] this->name;
            this->name=NULL;
        }
    }

    void eat() {
        cout << "cat eat..." << endl;
    }
};

/**
 * 1.静态联编 outupt ->animal eat...
 * 调用testEat时，参数的地址已经绑定好了(早绑定，静态联编，编译阶段就确定好了地址)
 * 2.如果想调用cat的eat,不能提前绑定好函数的地址了，所以需要在运行时候再去确定函数地址(动态联编)
 *  写法eat()方法改为虚函数，在父类上声名虚函数
 */
void testEat(Animal &animal) {
    animal.eat();
}


/**
 * 多态实现计算器
 */

class AbstractCalculator {
public:
    /**
     * 虚函数
     * virtual int getResult() {return 0;}
     * @return
     */

    /**
     * 纯虚函数
     * 1.如果父类有纯虚函数，子类在继承的时候必须实现这些纯虚函数
     * 2.如果类里函数纯虚函数，这个类抽象函数，不能实例化对象
     * 3.virtual int getResult()=0; 告诉编译器在vrable中为函数保留一个位置，但这个特定位置不放地址
     * @return
     */
    virtual int getResult()=0;

    int getVal1() const {
        return val1;
    }

    void setVal1(int val1) {
        this->val1 = val1;
    }

    int getVal2() const {
        return val2;
    }

    void setVal2(int val2) {
        this->val2 = val2;
    }

private:
    int val1;
    int val2;
};

//加法计算器
class PlusCalculator:public AbstractCalculator{
public:

    virtual int getResult() {
        return this->getVal1()+this->getVal2();
    }
};

//减法法计算器
class SubCalculator:public AbstractCalculator{
public:

    virtual int getResult() {
        return this->getVal1()-this->getVal2();
    }
};


class A:public AbstractCalculator{
public:
    int getResult() override {
        return 0;
    }
};

void testCalculator(){
//     AbstractCalculator  *ac = new PlusCalculator;
    AbstractCalculator  *ac = new SubCalculator;
     ac->setVal1(20);
     ac->setVal2(10);
     int plus = ac->getResult();
     cout<<"plus= "<< plus<<endl;

}

void polymorphism() {

#if 0

#endif

    //testCalculator();
    //如果发生了继承关系，编译器允许进行类型转换
    Animal *animal = new Cat("Tom");
    animal->eat();
    delete animal;
}