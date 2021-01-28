//
// Created by lipnegju on 2019-07-22.
//

#include <iostream>
#include <gtest/gtest.h>

using namespace std;


int num = 200;



//----------------------::作用域运算符--------------------
/**
 * 1.namespace命名空间主要解决命名冲突的
 * 2.namespace下可以放函数，变量，结构体，类
 * 3.命名空间必须定义在全局作用域下
 * 4.命名空间可以嵌套命名空间
 * 5.命名空间是开放的，可以随时添加内容
 * 6.命名空间名字相同会合并，合并后取交集
 */
namespace A{
    void a();
}

namespace A{
    void  a();
    void b();
}

namespace B{
    void a();
}

namespace C{
    void a();
    namespace D{
        void a();
    }

    struct Person{
        int age;
        char *name;
    };

    int sex;
}


//匿名namespace 相当于定了 static int a,static int b;只能在当前文件中使用
namespace {
    int a ;
    int c ;
}

namespace veryLongName{
    int a =30;
}

void  A::a() {
    cout<<"namespace A->a()\n";
}


void B::a() {
    cout<<"namespace B->a()\n";
    //命名空间起别名
    namespace vln = veryLongName;
    cout<<vln::a;
}





//----------------------::作用域运算符--------------------
void print(){
    int num =100;

//    cout << num<< endl;
      cout<<num <<"\n";
      //双冒号(作用域运算符)->全局作用域
      cout<<::num <<"\n";//
      cout<<::num<<"\n";
}





//----------------------using---------------------------

namespace E{
    int c=10;
}

void testUsing(){
//    int c =20;

    /**
     * 1.写了using 后，下面这行代码说明以后看到的c 就是用E namespace下的
     * 2.但是编译器的就近原则，全使用当前方法中的a ,产生了二义性，编译器报错
     */
    using  E::c;

   //using 编译指令 ，
//   using namespace E;

    cout<<c<<endl;
}





//----------------------c++对c语言的增强---------------------------

/**
 * 1.全局变量的检测增强
 */

/**
 * int  a;
 *int a =10; c可以运行 c++中会报错，重复定义
 */

/**
 * 函数检测增强
 * 1.c++必须有参数类型，和返回值，c语言只是报错
 * 2.c++调用函数时，参数列表必须匹配
 *
 */

int getRect(int w,int h){
    return  w*h;
}

/**
 * 3.类型转换增强
 */
void typeCast(){
    char * p = (char *)malloc(sizeof(char));
}

/**
 * 4.c++结构体中可以有函数
 */
struct  Person{
    int age;
    int addAge();
};

/**
 * 5.c++中使用结构体时可以不加struct
 */
void testStruct(){
    struct Person person;//
    Person person1;
}

/**
 *6. bool增强
 */

void testBool(){
    bool  falg;
}

/**
 * 7.三目运算符的区别？
 */


/**
 * 8 .const的区别
 * 1.c语言
 *   1.1 const 修饰全局变量，是不可以修改的，因为放在常量区，受保护的
 *   1.2 const 修饰局部变量，是伪常量，可以通过指针修改
 * 2.c++
 *  2.1 const 修饰全局变量，是不可以修改的，因为放在常量区，受保护的
 *  2.2 const 修饰局部变量，是真正的常量，不能修改，为什么不能修改？
 *      2.2.1 C语言中const修饰的变量是伪常量，编译器是会分配内存的，只要分配内存就可以修改内存中的值
 *            C++中 const不会分配内存 而是放到符号表中，一个常量符号对应一个值，以后只要找这个符号都是一个值
 *      2.2.2 const int a = 20; int *p = (int *)&a, *p = 200 为啥不能修改常量值的原理
 *             1.编译器会临时开辟一块内存空间
 *             2.int tmp = a//tmp有内存
 *             3.int *p=(int *)&tmp *p指向的是临时的那块空间，临时空间看不到
 *
 * 3.内部链接与外部链接
 *   3.1 c语言中 const int a 默认是外部链接
 *   3.2 c++ 中 const int a 默认是内部链接
 *
 * 4.const 分配内存情况
 *   4.1  const int a =10; int *p = (int *)&a 取地址会分配临时内存
 *   4.2  extern const int a =10 ,加了extern 编译器也分给const 变量分配内存
 *   4.3  int a =10; const int b = a; 用普通变量初始化const 的变量也会分配内存
 *   4.4  自定义数据类型 加const也会分配内存
 *        struct Person{
 *          int age;
 *          string name;
 *        };
 *
 *        const Person p1;
 *
 * 5. const 与 define区别
 *   5.1 尽量用const 代替define
 *   5.2 const 有类型，可进行编译器类型安全检查， #define 无类型，不可进行安全检查
 *   5.3 const 有作用域，#define 不重视作用域 默认定义处到文件结尾
 *
 */





//----------------------引用的基本语法与注意事项---------------------------

/**
 * 1.引用基本使用
 *   1.1.引用就是起别名
 *   1.2. &写在左边是引用，写到右边是取地址
 *   1.3.引用必须初始化， 引用初始化就不能修改了
 *
 * 2.引用注意事项
 *   2.1 引用必须引用一块合法的内存空间
 *   2.2 不要返回局部变量的引用
 *   2.3 如果函数的返回值是引用，那么这个函数调用可以作为左值使用
 *
 * 3.引用的本质
 *   3.1 int a = 10; int &aref = a;// 自动转换为 int * const aref = &a ,这也能说明引用为什么必须初始化
 *       aref = 20 //内部发现aref是引用，自动帮我们转换成 * aref = 20;
 *
 * 4.指针的引用
 * 5.常量引用
 */

void testRef(){
    int a = 10;
    int c =30;
    //引用必须初始化， 引用初始化化就不能修改了
    int &b = a;
    cout<<a<<"\n";
    cout<<b<<"\n";
    b=20;
    cout<<b<<"\n";

    //对数组建立引用 第一种方式
    int arr[10];

    for (int i = 0; i <10 ; ++i) {
        arr[i]=i;
    }

    int (&array)[10]=arr;

    for (int j = 0; j <10 ; ++j) {
        cout<<array[j]<<"，";
    }

    //对数组建立引用 第二种方式

    typedef int(ARRAY1)[10];//一个具有10个元素的int类型的数组

    cout<<"\n";
    ARRAY1  &array1 = arr;
    for (int k = 0; k <10 ; ++k) {
        cout<<array1[k]<<"-";
    }
}


void myTest(){
    cout<<"myTest";
}

void myTest1(){
    cout<<"myTest  11";
}

TEST(MyTEST ,测试1){
    myTest();
}

TEST(MyTEST1 ,测试1){
    myTest1();
}

/**
 * 值传递
 * @param a
 * @param b
 */
void swap(int a ,int b){
    int tmp = a;
    a=b;
    b=tmp;
    cout<<"\n"<<"swap"<<"a= "<<a<<" b= "<<b;
}

/**
 * 地址传递
 */
void swap1(int * a,int * b){
    int tmp = *a;
    *a=*b;
    *b = tmp;

    cout<<"\n"<<"swap1"<<"a= "<<*a<<" b= "<<*b;

}

/**
 * 引用传递 与指针一样，可以修改原始值
 */

void swap2(int &a,int &b){
    int tmp = a;
    a = b;
    b = tmp;
    cout<<"\n"<<"swap1"<<"a= "<<a<<" b= "<<b;
}
void testPassParms(){
    int a=10;
    int b =20;
//    swap(a,b);
//     swap1(&a,&b);
    int &c = a;
    int & d = b;
//    swap2(c,d);
    swap2(a,b);
    cout<<"\n"<<"testPassParms"<<"a= "<<a<<" b= "<<b;
}



/**
 *
 * p 指针的指针
 * *p 对象的指针
 * **p 具体的person对象
 *
 */
void allocMemory(Person **p){
    *p = (Person *)malloc(sizeof(Person));
}

/**
 * 指针引用开辟空间
 */
void allocMemory1(Person * &p){
    p = (Person *)malloc(sizeof(Person));
}

/**
 * 指针的引用
 */
void testRefPointer(){
   Person *p = NULL;
}

/**
 * 常量引用
 */

void constRef(){
//    int &ref = 10; //引用了不合法的内存
   const int &ref = 10;// 加入const后 ，编译器处理方式为 int tmp = 10 ,const init &ref = tmp;

   int * p =(int *) &ref;
   *p = 90;
   cout<<*p;
}



GTEST_API_ int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();

//    print();
//    A::a();
//    B::a();
//    testUsing();
//    testRef();
//    testPassParms();
//    testRefPointer();
//     constRef();
}