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
void insert(struct LinkNode *head,int src,int dest);
//3.删除
void delete(struct LinkNode *head,int value);
//4.查找
int query(struct LinkNode *head,int value);
//5.修改
int update(struct LinkNode *head,int value);
//6.清空
int clear(struct LinkNode *head);
//7.销毁
void destroy(struct LinkNode *head);
//8.遍历
void forEach(struct LinkNode *head);

#ifdef __cpluscplus
}
#endif
