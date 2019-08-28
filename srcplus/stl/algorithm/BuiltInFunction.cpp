//
// Created by lipengju on 2019-08-29.
//

#include "BuiltInFunction.h"
#include<iostream>
using namespace std;
//内建函数对象头文件
#include <functional>
#include <vector>
#include <algorithm>

void testNegate()
{
    //template<class T> T negate<T>//取反仿函数
    negate<int>n;

    cout << n(10) << endl;

    //加法  template<class T> T plus<T>//加法仿函数

    plus<int> p;

    cout << p(1, 1) << endl;
}

//template<class T> bool greater<T>//大于

void testGreater()
{
    vector<int>v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), [](int val){ cout << val << " "; });
}
