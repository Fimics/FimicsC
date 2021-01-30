//
// Created by lipnegju on 2019-07-28.
//

#include <iostream>
#include <cstring>
#include <gtest/gtest.h>
#include "String.h"

using namespace std;

MyString::MyString(const char *str) {
    cout<<"MyString init...\n";
     this->pstring= new char[strlen(str)+1];
     strcpy(this->pstring,str);
     this->size=strlen(str);
}

MyString::MyString(const MyString &str) {
    cout<<"MyString copy init...\n";
    this->pstring = new char[strlen(str.pstring)+1];
    strcpy(this->pstring,str.pstring);
    this->size=str.size;
}

/**
 * 重载<<
 * @param cout
 * @param str
 * @return
 */
ostream& operator<<(ostream& cout,MyString & str){
      cout<<str.pstring;
    return  cout;
}

istream& operator>>(istream& cin,MyString &str){
    cout<<"input string:\n";

    //清空原有的数据
    if(str.pstring!=NULL){
        delete [] str.pstring;
        str.pstring=NULL;
    }

    //用户输入的内容
    char buf[1024];
    cin>>buf;

    //把用户输入的内容拷贝到str
    str.pstring = new char[strlen(buf)+1];
    strcpy(str.pstring,buf);
    str.size = strlen(buf);
    return cin;

}

MyString& MyString::operator=(const char *str) {
    if(this->pstring!=NULL){
        delete [] this->pstring;
        this->pstring=NULL;
    }

    this->pstring = new char[strlen(str)+1];
    strcpy(this->pstring,str);
    return *this;
}

MyString& MyString::operator=(const MyString &str) {
    if(this->pstring!=NULL){
        delete [] this->pstring;
        this->pstring=NULL;
    }

    this->pstring = new char[strlen(str.pstring)+1];
    strcpy(this->pstring,str.pstring);
    return *this;
}

char &MyString::operator[](int index) {
    return this->pstring[index];
}

MyString MyString::operator+(const char *str) {
    int newSize = strlen(str)+this->size+1;
    char * tmp = new char[newSize];
    memset(tmp,0,newSize);
    strcat(tmp,this->pstring);
    strcat(tmp,str);
    MyString newStr(tmp);
    delete [] tmp;
    return newStr;
}

MyString MyString::operator+(const MyString &str) {
    int newSize = strlen(str.pstring)+this->size+1;
    char * tmp = new char[newSize];
    memset(tmp,0,newSize);
    strcat(tmp,this->pstring);
    strcat(tmp,str.pstring);
    MyString newStr(tmp);
    delete [] tmp;
    return newStr;
}

MyString::~MyString() {
     cout<<"MyString destroy\n";
     if(this->pstring!=NULL){
         delete [] this->pstring;
         this->pstring=NULL;
     }
}

bool MyString::operator==(const char *str) {
    if(strcmp(this->pstring,str)==0 && this->size==strlen(str)){
        return true;
    }else{
        return false;
    }
}

bool MyString::operator==(const MyString &str) {
    if(strcmp(this->pstring,str.pstring)==0 && this->size==strlen(str.pstring)){
        return true;
    }else{
        return false;
    }
}

//TEST(string,MyString){
//    MyString str="hello";
//    cout<<str;
//
//    int a =10;
//    cin>>a;
//    cout<<"a="<<a<<endl;
//
//    cin>>str;
//    cout<<str;
//
////    MyString str ="abc";
//    MyString str2(str);
//    MyString str3="333";
//    str3=str2;
//    str3="bbb";
//
//    cout<<str3<<endl;
//    char c = str3[1];
//    cout<<"c= "<<c<<endl;
//
//    MyString str4 = str+str3;
//    cout<<"str4="<<str4<<endl;
//
//}