//
// Created by lipengju on 2019-08-29.
//

#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

class MyPrint : public binary_function<int, int, void> {
public:
    void operator()(int v, int start) const {
        cout << "v = " << v << " start = " << start << " v+start = " << v + start << endl;
    }

};

void testAdapt01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    cout << "请输入起始值" << endl;
    int num;
    cin >> num;

    //for_each(v.begin(), v.end(), bind2nd( MyPrint(),num) );
    for_each(v.begin(), v.end(), bind1st(MyPrint(), num));
}

//第一步 绑定 数据 bind2nd
//继承类 binary_function<参数类型1 ，参数类型2 ，返回值类型>
//加const修饰 operator()

class GreaterThenFive : public unary_function<int, bool> {
public:
    bool operator()(int v) const {
        return v > 5;
    }
};

//取反适配器
void testAdapt02() {
    //一元取反
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    //查找大于5的数字
    //需求改为 找小于5的数字
    //vector<int>::iterator pos =  find_if(v.begin(), v.end(), not1( GreaterThenFive()));

    vector<int>::iterator pos = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));
    if (pos != v.end()) {
        cout << "找到小于5的数字为 " << *pos << endl;
    } else {
        cout << "未找到" << endl;
    }
}
//一元取反适配器  not1
//继承 unary_function <参数类型1，返回值类型>
//const修饰


void MyPrint03(int v, int start) {
    cout << v + start << endl;
}

//函数指针适配器
void testAdapt03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    //将函数指针 适配为 函数对象
    // ptr_fun
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03), 100));
}

//成员函数适配器
class Person {
public:
    Person(string name, int age) {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson() {
        cout << "成员函数中：姓名： " << m_Name << " 年龄：" << m_Age << endl;
    }

    void plusAge() {
        this->m_Age = this->m_Age + 100;
    }

    string m_Name;
    int m_Age;
};

void MyPrintPerson(Person &p) {
    cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

void testAdapt04() {
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 15);
    Person p3("ccc", 18);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    //成员函数适配器
    // mem_fun_ref
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::plusAge));
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::showPerson));


}