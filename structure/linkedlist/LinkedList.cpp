//
// Created by pengju.li on 2019-10-30.
//

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../common/linearList.h"
#include "../common/Expect.h"
#include "Node.h"
using namespace std;

template<class T>
class LinkedList : public linearList<T> {

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

    int indexOf(const T &element) const ;

    void insert(int index, const T &theElement);

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
int LinkedList<T>::indexOf(const T &element) const {

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
void LinkedList<T>::insert(int index, const T &theElement) {

    if(index<0 ||index>listSize){
        ostringstream s;
        s<<"index ="<<index<<" size = "<<listSize;
        throw illegalIndex(s.str());
    }

    if(index ==0){
        //在链表头部插入
        head = new Node<T>(theElement,head);
    } else{
        //寻找前驱节点
        Node<T> * p = head;
        for (int i = 0; i <index-1 ; i++) {
            p= p->next;
        }

        //在p之后插入
        p->next= new Node<T>(theElement,p->next);
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


// overload <<
template <class T>
ostream& operator<<(ostream& out, const LinkedList<T>& x)
{x.output(out); return out;}

#if 1
int main(){
    linearList<double> * x = new LinkedList<double>;
    LinkedList <int> y ,z;

    // test size
    cout << "Initial size of x, y, and z = "
         << x->size() << ", "
         << y.size() << ", "
         << z.size() << endl;

    // test empty
    if (x->empty()) cout << "x is empty" << endl;
    else cout << "x is not empty" << endl;
    if (y.empty()) cout << "y is empty" << endl;
    else cout << "y is not empty" << endl;

    // test insert
    y.insert(0, 2);
    y.insert(1, 6);
    y.insert(0, 1);
    y.insert(2, 4);
    y.insert(3, 5);
    y.insert(2, 3);
    cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
    cout << "Size of y = " << y.size() << endl;
    if (y.empty()) cout << "y is empty" << endl;
    else cout << "y is not empty" << endl;
    y.output(cout);
    cout << endl << "Testing overloaded <<" << endl;
    cout << y << endl;

    // test indexOf
    int index = y.indexOf(4);
    if (index < 0) cout << "4 not found" << endl;
    else cout << "The index of 4 is " << index << endl;

    index = y.indexOf(7);
    if (index < 0) cout << "7 not found" << endl;
    else cout << "The index of 7 is " << index << endl;

    // test get
    cout << "Element with index 0 is " << y.get(0) << endl;
    cout << "Element with index 3 is " << y.get(3) << endl;

    // test erase
    y.erase(1);
    cout << "Element 1 erased" << endl;
    cout << "The list is "  << y << endl;
    y.erase(2);
    cout << "Element 2 erased" << endl;
    cout << "The list is "  << y << endl;
    y.erase(0);
    cout << "Element 0 erased" << endl;
    cout << "The list is "  << y << endl;

    cout << "Size of y = " << y.size() << endl;
    if (y.empty()) cout << "y is empty" << endl;
    else cout << "y is not empty" << endl;

    try {y.insert(-3, 0);}
    catch (illegalIndex e)
    {
        cout << "Illegal index exception" << endl;
        cout << "Insert index must be between 0 and list size" << endl;
        e.outputMessage();
    }

    // test copy constructor
    LinkedList<int> w(y);
    y.erase(0);
    y.erase(0);
    cout << "w should be old y, new y has first 2 elements removed" << endl;
    cout << "w is " << w << endl;
    cout << "y is " << y << endl;

    // a few more inserts, just for fun
    y.insert(0,4);
    y.insert(0,5);
    y.insert(0,6);
    y.insert(0,7);
    cout << "y is " << y << endl;

    return 0;
}

#endif