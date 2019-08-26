//
// Created by lipengju on 2019-08-27.
//

#include "StringContainer.h"
#include <iostream>
#include <string>
using namespace std;


void testStringApi(){
    string a = string();//创建一个空字符串
    string b = string("abc");
    cout<<"a ="<<a<<" b ="<<b<<endl;
}

void stringContainer(){
     cout<<"stringAPI"<<endl;
     testStringApi();
}