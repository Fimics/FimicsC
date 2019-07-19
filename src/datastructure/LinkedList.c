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
#include <stdbool.h>

#if 1
//---------------------------链表结点定义-------------------------

//1.初始化链表
struct LinkNode *init(){
    struct LinkNode *header = malloc(sizeof(struct LinkNode));
    header->data=-1;
    header->next=NULL;

    struct LinkNode *tail = header;

#if 0

    int val = -1;
    while (true) {
        printf("输出插入的数据");
        scanf("%d",&val);
        if (val == -1){
            break;
        }

        struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
        newNode->data = val;
        newNode->next = NULL;

        //新节点插入到链表中
        tail->next = newNode;
        tail=newNode;
    }
#endif

    for (int i = 0; i <10 ; ++i) {
        struct LinkNode *node = malloc(sizeof(struct LinkNode));
        node->data=i;
        node->next=NULL;

        //新节点链接到链表中
        tail->next=node;
        tail=node;
    }

    return header;
}
//2.插入
void insert(struct LinkNode *header,int src,int dest){

    if(NULL==header) return;

    struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
    newNode->data=dest;
    newNode->next=NULL;

    struct LinkNode *node = header->next;
    while (node!=NULL){
        if(node->data==src){
            newNode->next=node->next;
            node->next=newNode;
            break;
        }
        node=node->next;
    }

}
//3.删除
void delete(struct LinkNode *header,int value){


    if(NULL==header) return;

    struct LinkNode *node = header->next;
    struct LinkNode *previousNode =node;
    while (node!=NULL){
        if(node->data==value){
            node->data=0;
            previousNode->next=node->next;
            free(node);
            node=NULL;

            break;
        }
        previousNode=node;
        node=node->next;
    }

}
//4.查找
int query(struct LinkNode *header,int value){

    if(NULL==header) return -1;

    int index =0;
    struct LinkNode *node = header->next;
    while (node!=NULL){
        if(node->data==value){
            break;
        }
        node=node->next;
        index++;
    }

    return index;
}
//5.修改
int update(struct LinkNode *header,int oldValue,int newValue){
    if(NULL==header) return -1;

    struct LinkNode *node = header->next;
    while (node!=NULL){
        if(node->data==oldValue){
            node->data=newValue;
            return 1;
        }
        node=node->next;
    }
    return -1;
}
//6.清空
int clear(struct LinkNode *header){

    if(NULL==header) return -1;

    struct LinkNode *node = header->next;
    while (node!=NULL){
        node->data=0;
        node=node->next;
    }

    return 1;
}
//7.销毁
void destroy(struct LinkNode *header){
    if(NULL==header) return;

    struct LinkNode *current = header->next;
    struct LinkNode * previosNode;
    while (current!=NULL){
        current->data=0;
        previosNode=current;
        current=previosNode->next;

        free(current);
    }

    if(header!=NULL){
        free(header);
        header=NULL;
    }

}
//8.遍历
void forEach(struct LinkNode *header){
    if(NULL==header) return;

    printf("------------------forEach start----------------\n");
    struct LinkNode * current = header->next;
    while (current!=NULL){
        printf("%d ,",current->data);
        current=current->next;
    }
    printf("\n------------------forEach end---------------\n");
}

//9.Reverse
void reverse(struct LinkNode *header){
    if(NULL==header) return;

    struct LinkNode * current = header->next;
    struct LinkNode * previous =NULL;
    struct LinkNode * next=NULL;// 1  2 3  4
                                // p  c n
                                //    p c  n

    while (current!=NULL){
       next=current->next;// p = 1 ,c = 2 ,n =3
       current->next=previous;// 1<- currnet.next
       previous=current;// p =2;
       current=next;//c = 3
    }
}

#endif

void linkedList() {

#if 0
#endif
    //1.初始化
    struct LinkNode *header = init();
    forEach(header);

    //9.逆序
    printf("Reverse \n");
    reverse(header);
    forEach(header);
//    //2.查找
//    int index = query(header,5);
//    printf("index of element in linkedList %d\n",index);
//    //3.修改
//    printf("update \n");
//    update(header,5,50);
//    forEach(header);
//    //4.插入
//    printf("insert \n");
//    insert(header,6,60);
//    forEach(header);
//    //5.删除
//    printf("delete \n");
//    delete(header,3);
//    forEach(header);
//    //6.清空
//    printf("clear \n");
//    clear(header);
//    forEach(header);
//    //7.销毁
//    printf("destroy \n");
//    destroy(header);
//    forEach(header);
}