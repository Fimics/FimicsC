//
// Created by lipnegju on 2019-07-22.
//

#include <iostream>
#include "Basic.h"

using namespace std;

int num = 200;

#if 0

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

#endif

#if 0

//----------------------::作用域运算符--------------------
void print(){
    int num =100;

//    cout << num<< endl;
      cout<<num <<"\n";
      //双冒号(作用域运算符)->全局作用域
      cout<<::num <<"\n";//
}

#endif

#if 1

//----------------------using---------------------------

namespace E{
    int c=10;
}

void testUsing(){
    int c =20;

    /**
     * 1.写了using 后，下面这行代码说明以后看到的a 就是用E namespace下的
     * 2.但是编译器的就近原则，全使用当前方法中的a ,产生了二义性，编译器报错
     */
   // using  E::a;

   //using 编译指令 ，
   using namespace E;

    cout<<c<<endl;
}

#endif

void basic() {
#if 0
    print();
    A::a();
    B::a();
#endif
   testUsing();

}