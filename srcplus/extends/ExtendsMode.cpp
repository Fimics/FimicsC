//
// Created by lipnegju on 2019-07-31.
//

#include <iostream>
using namespace std;

class BasePage{

public:

    static int niceCount;
    int cCount =1;
    int sameCount=1;

    BasePage() {
        cout<<"BasePage init..."<<endl;
    }

    BasePage(int viewCount) {
        this->viewCount=viewCount;
        cout<<"BasePage init..."<<endl;
    }

    virtual ~BasePage() {
        cout<<"BasePage destroy..."<<endl;
    }

    void header(){
        cout<<"header"<<endl;
    }

    void footer(){
        cout<<"footer"<<endl;
    }

    string getContent(){
        return this->content;
    }

protected:
    int dCount=2;
    void left(){
        cout<<"left"<<endl;
    }

    void right(){
        cout<<"right"<<endl;
    }

private:
    int eCount=3;
    string content="base_page";
    int viewCount =1000;
    int getViewCount(){
        return viewCount;
    }
};

int BasePage::niceCount =1000;

/**
 * 1.先调用parent init-->child init-->child destroy-->parent destroy
 * 2.三种继承方式：->class News: public BasePage 所有的继承都不能访问到private属性
 *    public :int a ,protected int b, private int c
 *    2.1 public    : parent  public :int a ,protected int b, private x
 *    2.1 private   : parent  public :----- ,protected int b, int c ,private x 到子类都变成protected
 *    2.3 protected : parent  public :----- ,protected ---, private int a,int b 到子类都变成private
 * 3.通过sizeof(news)发现子类已经把parent的private 继承过来了，只是编译器通过权限做了隐藏，导致子类不能
 *   访问parent的private属性
 * 4.子类会继承父类的成员属性，和成员方法，但不会继承父类的构造函数，和析构函数，只有父类知道怎么构造和析构自己
 *   子类是不知道父类构造与析构的
 * 5.子类与父同名属性，优先调用子类的(就近原刚) ，
 * 6.继承中的同名处理  --> news.BasePage::sameCount
 *   6.1 成员属性，直接调用子类的，如果想调用父类的，需要作用域
 *   6.2 成员函数, 直接调用子类的，父亲类的所有版本都会被隐藏，可果想调用，需要作域
 *7.继承中静态成员处理
 *  7.1 静态成员属性可以被继承下来
 *  7.2 如果静态成员重名，会直接调用子类的，如果想访问父类的，可以通过域名访问
 *  7.3 静态成员函数也可以继承下来，如果同名，直接调用子类的，如果想调用父类的，通过作用域
 * 8.继承的概念与问题
 *   8.1
 *   8.2
 *
 */

class News: public BasePage{
public:

    int sameCount=2;
    News() {
        cout<<"news init..."<<endl;
    }

    /**
     * 用初始化列表，显示调用父类有参构造，
     * @param a
     */
    News(int a):BasePage(2) {
        cout<<"news init..."<<endl;
    }

    virtual ~News() {
        cout<<"news destroy..."<<endl;
    }

    void newsHeader(){
        cout<<"news_header"<<endl;
    }

private:
    int newsCount=100;
};

void testNews() {
    News news;
    cout<<"\nnews.sameCount= "<<news.sameCount<<endl;
    cout<<"\nnews->basePage->.sameCount= "<<news.BasePage::sameCount<<endl; //如果子类与父类成员同名，使用作用域调用父类成员
}

class ArmyNews:public News{
public:

    ArmyNews() {
        cout<<"ArmyNews init ...\n";
    }

    virtual ~ArmyNews() {
       cout<<"ArmyNews destroy ...\n";
    }
};

void testArmyNews(){
    ArmyNews news;
}

//--------------------------多继承----------------------------
class Base1{
public:
    Base1() {
        this->a=1;
        this->b=3;
    }

public:
    int a;
    int b;
};

class Base2{
public:
    Base2() {
        this->b=2;
    }

public:
    int b;
};

class Child:public Base1,public Base2{
public:
    int c;
    int d;
};


void testChild(){
    Child child;
    int b =child.Base1::b;//多继承二义性需要作用域

    cout<<"child size: "<< sizeof(Child)<<endl;
}

//--------------------------菱形继承----------------------------
/**
 * 菱形继承会有空间浪费 同继承了 Sheep ,Tuo的age
 * 1.解决方案
 *    虚继承,操作的是一份共享数据
 * 2.虚基类的内部工作原理
 *
 */

class Animal{
public:
    int age;
};

//虚基类Sheep
class Sheep:virtual public Animal{

};

//虚基类Tuo
class Tuo:virtual public Animal{

};

class SheepTuo:public Sheep, public Tuo{

};

void testSheepTuo(){
    SheepTuo st;
    st.Sheep::age=1;
    st.Tuo::age=2;

    cout<<"ages = "<<st.Sheep::age<<"  aget ="<<st.Tuo::age<<endl;

}

void pager(){
//    testNews();
//      testArmyNews();
// testChild();
     testSheepTuo();
}


