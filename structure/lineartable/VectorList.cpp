//
// Created by pengju.li on 2019-10-30.
//

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "LinearList.h"
#include "../common/Expect.h"
using namespace std;

template <class T>
class VectorList:LinearList{

public:

    VectorList(int initialCapacity =10);
    VectorList(const VectorList<T> &);
    ~VectorList() {}

    //ADT method
private:
    bool empty() const {
        return false;
    }

    int size() const override {
        return 0;
    }

    T &get(int index) const override {
        return <#initializer#>;
    }

    int indexOf(const T &element) override {
        return 0;
    }

    void insert(int index, T &element) override {

    }

    void erase(int index) override {

    }

    void output(ostream &out) const override {

    }

protected:
    void checkIndex(int theIndex) const ;
    //存储线性表元素的向量
    vector<T>* element;
};

int main(){

}