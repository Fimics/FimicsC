//
// Created by pengju.li on 2019-10-30.
//

#include <iostream>

using namespace std;

template<class T>
class Iterator {
public:

    //用c++的typedef语句实现双向迭代器
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;

    Iterator(T *thePosition = 0) {
        position = thePosition;
    }

    //解引用
    T &operator*() const {
        return * position;
    }

    T *operator->() const {
        return &*position;
    }

    //迭代器的值增加

    //前加
    Iterator& operator++(){
        ++position;
        return this;
    }

    //后加
    Iterator operator++(int){
        Iterator old = this;
        ++position;
        return old;
    }

    //前减
    Iterator& operator--(){
        --position;
        return this;
    }

    //后减
    Iterator operator--(int){
        Iterator old = this;
        --position;
        return old;
    }

    //测试是否相等
    bool operator!=(const Iterator right) const {
        return position!=right;
    }

    bool operator==(const Iterator right) const {
        return position==right;
    }

protected:
    T * position;
};
