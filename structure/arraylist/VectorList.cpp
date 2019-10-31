//
// Created by pengju.li on 2019-10-30.
//

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../common/AbstractList.h"
#include "../common/Expect.h"
using namespace std;

template <class T>
class VectorList : public AbstractList<T>{

public:

    VectorList(int initialCapacity =10);
    VectorList(const VectorList<T> &);
    ~VectorList() {}

    //ADT method
    bool empty() const {
        return element->empty();
    }

    int size() const {
        return element->size();
    }

    T & get(int index) const;

    int indexOf(const T &element);

    void insert(int index, T &element);
    void erase(int index);

    void output(ostream &out) const;

    int capacity() const {
        return element->size();
    }

    //线性表的起始和结束位置的迭代器
    typedef typename vector<T>::iterator iterator;
    iterator begin(){
        return element->begin();
    }

    iterator end(){
        return element->end();
    }

protected:
    void checkIndex(int theIndex) const ;
    //存储线性表元素的向量
    vector<T>* element;
};

//int main(){
//
//}