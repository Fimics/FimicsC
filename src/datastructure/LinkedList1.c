//
// Created by lipnegju on 2019-07-21.
//



#include "LinkedList1.h"

struct Test{
    char  * name;
    int age;
};

//链表结点数据类型
struct LinkNode{
    void *data;
    struct LinkNode *next;
};

//链表数据类型
struct LList{
    struct LinkNode header;
    int size;
};

//初始化链表
LinkList init1(){
  struct LList * list = malloc(sizeof(struct LList));
  if(NULL==list) return NULL;

  list->header.data=NULL;
  list->header.next=NULL;
  list->size=0;
  return list;
}

//插入
void insert1(LinkList list,int pos, void *data){
    if(NULL==list|| data==NULL) return;

    struct LList * myList = (struct LList *) list;

    if(pos<0 || pos>myList->size) {
        pos=myList->size;
    }

    //处理辅助节点位置
    struct LinkNode *currnet = &(myList->header);
    for (int i = 0; i < pos; ++i) {
        currnet=currnet->next;
    }

    //创建节点
    struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
    newnode->data=data;
    newnode->next=NULL;

    //新节点插入到链表中
    newnode->next=currnet->next;
    currnet->next=newnode;

    myList->size++;
}


//遍历
void foreach1(LinkList list,FOREACH foreach){

    if(NULL==list || foreach==NULL) return;

    struct LList * mylist = (struct LList *)list;
    struct LinkNode *current = mylist->header.next;

    while (current!=NULL){
        foreach(current->data);
        current= current->next;
    }
}


void printTest(void * data){
    struct Test *test = (struct Test *)data;
    printf("test name--> %s ,age--> %d \n",test->name,test->age);
}




void linkedList1(){
     LinkList  list = init1();

    for (int i = 0; i <10 ; ++i) {
        struct Test * test = malloc(sizeof(struct Test));
        test->name = malloc(sizeof(char)*20);
        strcpy(test->name,"test");
        test->age=i;
        insert1(list,i,test);
    }


    foreach1(list,printTest);
}