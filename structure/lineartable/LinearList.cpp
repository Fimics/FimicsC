//
// Created by pengju.li on 2019-10-28.
//

#include <iostream>

using namespace std;

template<class T>
class LinearList {
 public:
    virtual ~LinearList() {}

    virtual bool empty() const =0;

    virtual int size() const =0;

    virtual T& get(int index) const =0;

    virtual int indexOf(const T& element) const =0;

    virtual void insert(int index,T& element)  =0;

    virtual void erase(int index)=0;

    virtual void forEach() const =0;

    virtual void output(ostream& out) const =0;
};

template <class T>
class ArrayList:public LinearList<T>{

public:

    //构造函数，复制构造函数，析构函数
    ArrayList(int initialCapacity=10);
    ArrayList(const ArrayList<T>&);
    ~ArrayList(){
        delete [] element;
    }

    //ADT方法
    bool empty() const {
        return listSize==0;
    }

    int size() const  {
        return listSize;
    }

    T &get(int index) const;

    int indexOf(const T &element);

    void insert(int index, T &element);

    void erase(int index);

    void forEach();

    void output(ostream &out);

    //其他方法
    int capacity(){
        return arrayLength;
    }

protected:
    void checkIndex(int inidex) const;
    //存储线性表元素的一维数组
    T * element;
    //数组容量
    int arrayLength;
    //线性表元素个个数
    int listSize;
};