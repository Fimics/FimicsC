//
// Created by lipengju on 2019-08-26.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void myPrint(int v){
    cout<<v<<endl;
}

/**
 * 容器遍历
 */
void testVector1(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    cout<<v[1]<<endl;

    //遍历方式一
//    vector<int>::iterator itBegin= v.begin();
//    vector<int>::iterator itEnd = v.end();
//
//    while (itBegin!=itEnd){
//        cout<<*itBegin<<endl;
//        itBegin++;
//    }

    //遍历第二种方式
//    for (vector<int >::iterator itb=v.begin();itb!=v.end();itb++) {
//        cout<<*itb<<endl;
//    }

    //第三种方式，用算法
    for_each(v.begin(),v.end(),myPrint);
}

/**
 * 操作自定义数据类型
 */

class Person{
public:
    Person(int height,int age){
        this->height=height;
        this->age=age;
    }

    int age;
    int height;
};

void myPersonPrint(Person  *p){
    cout<<"height="<<p->height<<" age "<<p->age<<endl;
}

void iteratorPerson(){
    vector<Person> vp;
    Person p1 (100,1);
    Person p2(200,2);
    Person p3(300,3);
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);

    for (vector<Person>::iterator it=vp.begin(); it!=vp.end() ; it++) {
        Person p = (*it);
        int height = p.height;
        int age = p.age;
        cout<<"height= "<<height<<" age ="<<age<<endl;
    }
}

/**
 * 存放自定义数据类型的指针
 */
void iteratorPerson1(){
    vector<Person *> vp;
    Person p1 (100,1);
    Person p2(200,2);
    Person p3(300,3);
    vp.push_back(&p1);
    vp.push_back(&p2);
    vp.push_back(&p3);

    for (vector<Person *>::iterator it=vp.begin(); it!=vp.end() ; it++) {
        Person *p = (*it);
        int height = p->height;
        int age = p->age;
        cout<<"height= "<<height<<" age ="<<age<<endl;
    }

    cout<<"-----------------------------------------"<<endl;
    //容器嵌套
    vector<vector<int>>  v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    for (int i = 0; i <5 ; ++i) {
        v1.push_back(i);
        v2.push_back(i+10);
        v3.push_back(i+20);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    for (vector<vector<int >>::iterator it=v.begin(); it!=v.end() ; it++) {
        vector<int> vchild = *it;
        cout<<"==================="<<endl;
        for (vector<int>::iterator cit=vchild.begin(); cit!=vchild.end() ; cit++) {
            cout<<*cit<<endl;
        }
    }

}

void vectorContainer(){

//    testVector1();
//iteratorPerson();
//iteratorPerson1();

}