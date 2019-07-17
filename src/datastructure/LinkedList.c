//
// Created by lipnegju on 2019-07-16.
//

/**
 * 链表
 *  1.是由一系列结点组成，每个节点都包含数组与指针，链表在内存是非连续空间
 *  2.分类 动态链表，静态链表
 *    2.1 单向链表，双向链表，循环链表，单向循环链表，双向循环链表
 */

#include <stddef.h>
#include "LinkedList.h"

#if 1
//---------------------------链表结点定义-------------------------

//1.初始化链表
struct LinkNode *init(){
    struct LinkNode node1 = {10, NULL};
    struct LinkNode node2 = {20, NULL};
    struct LinkNode node3 = {30, NULL};
    struct LinkNode node4 = {40, NULL};
    struct LinkNode node5 = {50, NULL};
    struct LinkNode node6 = {60, NULL};

    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    node4.next=&node5;
    node5.next=&node6;

    return &node1;
}
//2.插入
void insert(struct LinkNode *head,int src,int dest){

}
//3.删除
void delete(struct LinkNode *head,int value){

}
//4.查找
int query(struct LinkNode *head,int value){

}
//5.修改
int update(struct LinkNode *head,int value){

}
//6.清空
int clear(struct LinkNode *head){

}
//7.销毁
void destroy(struct LinkNode *head){

}
//8.遍历
void forEach(struct LinkNode *head){
    //遍历链表?
    //定义辅助指针
    struct LinkNode *curNode=head;

    while (curNode!=NULL){
        printf("%d\n",curNode->data);
        //指针移向下一个元素首地址
        curNode=head->next;
    }
}

#endif

void linkedList() {

#if 0
#endif
    struct LinkNode *head = init();
    forEach(head);

}