//
// Created by pengju.li on 2019-07-31.
//

#include <iostream>

using namespace std;

/**
 * 指针:
 * 1.一定要在解除引用运算(*)之前，把指针始化一个确定的，适当的地址，这是使用指针的金科玉律(不然会出现野指针)
 */


void testNew() {
    int a;
    int * p = &a;
    *p = 10;
    cout << "*p = " << *p <<" a="<<a<< endl;

    /**
     *1.new int 会根据类型来确定需要多少内存，然后找到这样的内存并返回，赋值给pn
     *2.new 分配的内存在heap区
     *3.值为0的指针为空指针
     */
    int * pn = new int;
    *pn = 20;
    cout << "*pn = " << *pn << endl;

}

void testDelete() {
    int * ps = new int;
    /**
     * 1.delete ps 会释放ps指向的内存，但不会删指针ps本身
     * 2.一定要配对的使用 new ,delete 否则发生内存泄漏
     * 3.不能使用delete来释放申明变量所获得的内存
     */
    delete (ps);
    ps = NULL;
}

void testNewArray(){
    int * array = new int[10];
    delete [] array;
    array=NULL;
}


//int main() {
////     testNew();
//    testDelete();
//}