//
// Created by lipnegju on 2019-07-19.
//


#pragma once

#ifdef __cpluscplus
extern "C"{
#endif

struct DNCArray{
    //数组存储元素的空间的首地址
    void ** addr;
    //存储数据的内存中最大能够容纳多少元素
    int capacity;//容量
    //当前存储数据的内存中有多少个元素
    int size ;//大小
};

/**
 * 初始化数组
 * @return
 */
struct DNCArray * inita(int capacity);

//插入元素
void inserta(struct DNCArray * array,int pos,void *data);
//遍历
void foreacha(struct DNCArray *array,void(* callback)(void *));
//删除
void removeItemByIndexa(struct DNCArray * da ,int pos);

void removeItemByValuea(struct DNCArray *da,void * data, int(*compare)(void *,void *));

int myCompare(void *data1 , void *data2);

void destroya(struct DNCArray *da);

#ifdef __cpluscplus
}
#endif

