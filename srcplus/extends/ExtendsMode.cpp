//
// Created by lipnegju on 2019-07-31.
//

#include <iostream>
using namespace std;

class BasePage{

public:

    static int niceCount;
    int cCount =1;

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
 */

class News: public BasePage{
public:

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

void pager(){
//    testNews();
      testArmyNews();
}


