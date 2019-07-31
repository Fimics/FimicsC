//
// Created by lipnegju on 2019-07-28.
//
#include <iostream>
using namespace std;

#ifndef FIMICSCPP_STRING_H
#define FIMICSCPP_STRING_H

class MyString{
public:

    friend ostream& operator<<(ostream& cout,MyString & str);
    friend istream& operator>>(istream& cin,MyString & str);
    MyString(const char * str);
    MyString(const MyString& str);
    MyString& operator=(const char * str);
    MyString& operator=(const MyString& str);
    char& operator[](int index);
    MyString operator+(const char * str);
    MyString operator+(const MyString& str);
    bool operator==(const char * str);
    bool operator==(const MyString& str);
    ~MyString();
private:
    char * pstring;//字符串堆区指针
    int size;
};
void myString();
#endif //FIMICSCPP_STRING_H
