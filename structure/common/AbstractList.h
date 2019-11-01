//
// Created by pengju.li on 2019-10-30.
//

#include <iostream>
using namespace std;

#ifndef FIMICSCSTRUCTURE_LINEARLIST_H
#define FIMICSCSTRUCTURE_LINEARLIST_H

template<class T>
class AbstractList {
public:
    virtual ~AbstractList() {}

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual T &get(int index) const = 0;

    virtual int indexOf(const T &element) = 0;

    virtual void insert(int index, const T &element) = 0;

    virtual void erase(int index) = 0;

    virtual void output(ostream &out) const = 0;
};

#endif //FIMICSCSTRUCTURE_LINEARLIST_H
