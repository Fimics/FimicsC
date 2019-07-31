//
// Created by pengju.li on 2019-07-31.
//

#include <iostream>
using namespace std;

/**
 * 指针:
 * 1.一一定要在解除引用运算(*)之前，把指针安始化一个确定的，适当的地址，这是使用指针的金科玉律(不然会出现野指针)
 */


void testNew(){
  int a;
  int * p =&a;
  *p = 10;
  cout<<"*p = "<<*p<<endl;

  /**
   *1.new int 会根据类型来确定需要多少内存，然后找到这样的内存并返回，赋值给pn
   *2.new 分配的内存在heap区
   *3.值为0的指针为空指针
   */
  int * pn = new int;
  *pn =20;
  cout<<"*pn = "<<*pn<<endl;
}


void fMemory(){
     testNew();
}