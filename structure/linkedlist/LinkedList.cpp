//
// Created by pengju.li on 2019-10-30.
//

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../common/AbstractList.h"
#include "../common/Expect.h"
#include "Node.h"
using namespace std;

template<class T>
class LinkedList : public AbstractList<T> {

public:

    //构造函数，复制构造函数，析构函数
    LinkedList(int initialCapacity = 10);

    LinkedList(const LinkedList<T> &);

    ~LinkedList();

    //ADT方法
    bool empty() const {
        return listSize == 0;
    }

    int size() const {
        return listSize;
    }

    T &get(int index) const;

    int indexOf(const T &element);

    void insert(int index, T &theElement);

    void erase(int index);

    void output(ostream &out) const;

protected:
    void checkIndex(int index) const;

    //存储线性表元素的一维数组
    T *element;
    //指向链表第一个节点的指针
    Node<T> * head;
    //线性表元素个个数
    int listSize;
};


/**
 * 构造函数
 * @tparam T
 * @param initialCapacity
 */
template <class T>
LinkedList<T>::LinkedList(int initialCapacity) {
    if(initialCapacity<1){
        ostringstream s;
        s<<"Initial capacity ="<<initialCapacity<<" Mustt be >0";
        throw illegalParameterValue(s.str());
    }

    head=NULL;
    listSize=0;
}

/**
 * 复制构造函数
 * @tparam T
 * @param theList
 */
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& theList) {

    listSize = theList.listSize;

    if(listSize==0){
        //链表为空
        head=NULL;
        return ;
    }

    //链表theList非空

    Node<T> * sourceNode = theList.head;
    //复制链表头节点
    head = new Node<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    Node<T> * targetNode = head;

    //复制剩余元素
    while (sourceNode!=NULL){
        targetNode->next = new Node<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    //链表结束
    targetNode->next=NULL;

}

/**
 * 析构函数
 * @tparam T
 */
template <class T>
LinkedList<T>::~LinkedList() {
    while (head!=NULL){
        Node<T> *nextNode = head->next;
        delete head;
        head =nextNode;
    }
}

template<class T>
void LinkedList<T>::checkIndex(int index) const {
    //确定index在 0和listSize-1之间
    if (index < 0 || index > listSize) {
        ostringstream s;
        s << "index= " << index << " size =" << listSize;
        throw illegalIndex(s.str());
    }
}

template <class T>
T& LinkedList<T>::get(int index) const {
    checkIndex(index);

    Node<T> * currentNode = head;
    for (int i = 0; i <index ; ++i) {
        currentNode=currentNode->next;
    }
    return currentNode->element;
}

template <class T>
int LinkedList<T>::indexOf(const T &element) {

    Node<T> * currentNode = head;
    //当前节点的索引
    int index =0;

    while (currentNode!=NULL&&currentNode->element!=element){
        currentNode = currentNode->next;
        index++;
    }

    //确定是否找到结点
    if(currentNode==NULL)
        return -1;
    else
        return index;

}

/**
 * 删除索引为index的元素
 * @tparam T
 * @param index
 */
template <class T>
void LinkedList<T>::erase(int index) {
    checkIndex(index);

    //index有效，需要找到要删除的无毒节点
    Node<T> * deleteNode;

    if(index==0){
        //删除链表首节点
        deleteNode = head;
        head=head->next;
    }else{
        //用指针p指向要删除节点的前驱节
        Node<T> * p = head;
        for (int i = 0; i <index -1; i++) {
            p=p->next;
        }

        deleteNode = p->next;
        p->next=p->next->next;
    }

    listSize--;
    delete deleteNode;
}

/**
 * 插入元素
 * @tparam T
 * @param index
 * @param theElement
 */
template <class T>
void LinkedList<T>::insert(int index, T &theElement) {

    if(index<0 ||index>listSize){
        ostringstream s;
        s<<"index ="<<index<<" size = "<<listSize;
        throw illegalIndex(s.str());
    }

    if(index ==0){
        //在链表头部插入
        head = new Node<T>(element,head);
    } else{
        //寻找前驱节点
        Node<T> * p = head;
        for (int i = 0; i <index-1 ; i++) {
            p= p->next;
        }

        //在p之后插入
        p->next= new Node<T>(element,p->next);
    }

    listSize++;
}

/**
 * 输出链表
 * @tparam T
 * @param out
 */
template <class T>
void LinkedList<T>::output(ostream &out) const {
    //把链表放入输出流
    for (Node<T> * currentNode = head;currentNode!=NULL;currentNode=currentNode->next) {
        out<<currentNode->element<<" ,";
    }
}


template <class T>
ostream& operator<<(ostream& out, const Node<T>& x){
    x.output(out);
    return out;
}


int main(){
    return 0;
}