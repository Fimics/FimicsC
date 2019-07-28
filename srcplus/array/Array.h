//
// Created by lipnegju on 2019-07-28.
//

#ifndef FIMICSCPP_ARRAY_H
#define FIMICSCPP_ARRAY_H

class MyArray{
public:
    MyArray();//默认构造 默认大小为100
    MyArray(int capacity);
    MyArray(const MyArray & array);

    void push(int value);//尾插法
    int get(int index);
    void update(int index,int value);
    virtual ~MyArray();

private:
    int *paddress;//指向真正存储数据的指针
    int size ;//数组大小
    int capacity;//数组容量
};

void  farray();
#endif //FIMICSCPP_ARRAY_H
