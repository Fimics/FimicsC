//
// Created by lipnegju on 2019-07-25.
//
#include <iostream>
#include <string>

using namespace std;

/**
 * 对象的实始化与清理
 * 1.构造函数与析构函数
 */


#if 1

//-----------------------------构造函数------------------------------

/**
 * 分类
 * 1.无参构造函数(默认构造函数) 有参构造函数
 * 2.普通构造函数 ，拷贝构造函数
 */

class Person {

public:
    /**
     * 构造函数
     * 1.与类名相同，没有返回值，不写void 可以发生重载(可以有参数)
     * 2.构造函数由编译器自动调用，而不是手动，而且只会调用一次
     */
    Person() {
        cout << "init" << "\n";
    }

    //重载
    Person(int age) {
        cout << "init int a" << "\n";
    }

    //拷贝构造函数
    Person(const Person &person) {
        cout << "init clone" << "\n";
    }

    void eat() {
        cout << "eating" << "\n";
    }

    int age;

public:
    /**
     * 析构函数
     * 1.与类名相同，类名前加一个符号"~" 也没有返回值，不写void 不可以有参数
     * 2.自动调用，而且只调用一次
     */
    virtual ~Person() {
        cout << "destrory" << "\n";
    }
};


void testInit() {
//    Person p;// Person p() 默认构造函数不能加() 加括号编译顺认为是函数声明
//    Person p1(1);
//    Person p2(p1);
//    p2.eat();

    Person p4 = Person(4);//显示调用
    //Person(4) 叫匿名对象 特点;如果编译器发现了对象是匿名的，那么在这行代码结束后就会释放这个对象

    /**
     * 1.不能用拷贝函数初始化匿名对象
     * 2.如果这样写，编译器认为写成了对象声明，如果写成右值可以
     */
//    Person(p4);
    Person p5 = Person(p4);

}

/**
 * 拷贝构造调用时机
 * 1.用已经创建好的对象来初始化新的对象
 */
void testCopy() {
    Person p1;
    p1.age = 10;
    Person p2(p1);
}

//2.以仠传递的方式给函数传值
void doCopy(Person p1) {
    Person p2(p1);
}

//拷贝函数应用3 ,以值方式返回局部对象
Person getPerson() {
    Person p1;
    return p1;
}

void testGetPerson() {
    Person person = getPerson();
}


//----------------------------构造函数的调用规则-------------------------------
/**
 * 默认情况下，c++编译器至少为我们写的类增加3个函数
 * 1.默认构造函数
 * 2.默认析构函数
 * 3.摸认拷贝函数(对类中非静态成员属性的简单拷贝)
 *
 * 4.如果用户定义拷贝构造函数，c++不会再提供任何默认构造函数
 * 5.如果用户定义了普通构造函数，c++不再提供无参构造函数，但会提供默认拷贝函数
 */


//----------------------------深拷贝浅拷贝-------------------------------

/**
 * 深拷贝
 *
 * 浅拷贝
 */

//----------------------------初始化列表-------------------------------

class Teacher {
public:
    int a;
    int b;
    int c;

    //有参构造函数
//    Teacher(int a,int b,int c) {
//        this->a=a;
//        this->b=b;
//        this->c=c;
//    }

    //用初始化列表，初始化数据
    Teacher(int a, int b, int c) : a(a), b(b), c(c) {
    }

    //列表默认值
    Teacher(): a(1), b(2), c(3){}
};

void testTeacher(){
//    Teacher teacher(1,2,3);
    Teacher teacher;
    cout<<"a= "<<teacher.a<<"  b= "<<teacher.b<<"  c= "<<teacher.c;
}

//----------------------------类作为类的成员-------------------------------

/**
 * 类对象作为类成员
 * 1.构造顺序先把成员类一一构造，然后再构造自己，析构是相反的，先析构自己，再析构成员类
 */

class Phone{

public:
    string phoneName;

    Phone() {
        cout<<"phone init\n";
    }

    Phone(string name){
        phoneName=name;
        cout<<"phone params init\n";
    }

    ~Phone(){
        cout<<"phone destroy\n";
    }
};

class Game{

public:
    Game() {
        cout<<"Game init\n";
    }

    Game(string name){
        gameName=name;
        cout<<"Game params init\n";
    }

    ~Game(){
        cout<<"Game destroy\n";
    }

    string gameName;
};

class Student{

public:

    Student() {
        cout<<"student init \n";
    }

    Student(string name) {
        studentName = name;
        cout<<"student params init \n";
    }

    virtual ~Student() {
       cout<<"student destroy\n";
    }

    string studentName;
    Phone phone;
    Game game;
};

void testStudent(){
    Student student("zhanshan");
    Phone phone("android");
    Game game("jump");

    student.phone=phone;
    student.game=game;
}

//----------------------------explicit关键字的作用-------------------------------

/**
 * explicit关键字的作用-->防止隐式类型转换
 */

class MyString{
public:
    MyString(const char *str){

    }

    explicit MyString(int strSize){
        size =strSize;
    }

    char * str;
    int size;
};

void testMyString(){
    MyString str="abc";
//    MyString str1 = 10;//等价于隐式类型转换 MyString str1 =MyString(10)
}


//------------------------------动态对象创建  new 运算符的使用-------------------------------

void testNew(){

//    Game game;//栈区开辟

      /**
       * new
       * 1.堆区开辟空间
       * 2.默认不会调用析构函数 ,但会调用构造函数
       * 3.所有new出来的对象，都会返回该类型的指针 ，malloc返回void * 还要强转，malloc不会调用构造函数
       * 4.delete game 释放对象 ，delete 与new 都是运算符
       * 5.
       */
      Game *game = new Game;
      delete  game;

      void * p =new Game;//会出现释放问题，不能释放对象
      delete p;

      //通过new开辟数组
      Game * games = new Game[10];//调用10次默认构造函数，所以一定要提供默认构造函数
      delete [] games;//释放数组必须加[]

      //在栈上开辟数组，可以指定有参函数
      Game games1[2]={Game("1"),Game("2")};


}

#endif

void initObject() {

#if 0
#endif
//    testInit();
//    testGetPerson();
//  testTeacher();
//    testStudent();
testNew();
}