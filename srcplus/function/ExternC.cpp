//
// Created by lipnegju on 2019-07-25.
//


#include "ExternC.h"

/**
 * c++中想调用c语言方法
 */

//extern "C" void show();//在其他文件中找这个show方法，而且这个方法是C语言的 已经包含了Extern.h方法，再用extern 会报错

void externC(){
    show(); //c++ 中函数是可以重载的，编译器会把这个函数名称偷偷改成 void _show()
}

//int main(){
//    externC();
//}