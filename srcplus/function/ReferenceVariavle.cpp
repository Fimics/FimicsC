//
// Created by pengju.li on 2019-08-01.
//

#include <iostream>
using  namespace std;


//--------------------------引用变量---------------------------------
/**
 * 1.引用是已定义变量的别名
 * 2.引用变量的用途主要是作为函数的形参，能过引用变量作为参数，函数将使用原始数据，而不是其副本
 * int rats;
 * int & rodents = rats, rodents与rats可以互换，它们指向的是相同的值和内存单元
 */


void testRefVariable(){
//   cout<<"testRefVariable"<<endl;
    int a =100;
    int & b = a;//引用变量定义
    b=b+100;
    cout<<"a = "<<a<<" b= "<<b<<endl;
    cout<<"&a = "<<&a<<" &b= "<<&b;

}


void referenceVariable(){
    testRefVariable();
}