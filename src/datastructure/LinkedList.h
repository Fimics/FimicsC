//
// Created by lipnegju on 2019-07-16.
//

#pragma once

#ifdef __cpluscplus
 extern "C"{
#endif

struct LinkNode {
    int data;
    struct LinkNode *next;
};


//1.初始化链表
struct LinkNode *init();
//2.插入
void insert(struct LinkNode *header,int src,int dest);
//3.删除
void delete(struct LinkNode *header,int value);
//4.查找
int query(struct LinkNode *header,int value);
//5.修改
int update(struct LinkNode *header,int oldValue,int newValue);
//6.清空
int clear(struct LinkNode *header);
//7.销毁
void destroy(struct LinkNode *header);
//8.遍历
void forEach(struct LinkNode *header);

#ifdef __cpluscplus
}
#endif
