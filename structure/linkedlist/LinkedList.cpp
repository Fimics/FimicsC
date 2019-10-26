//
// Created by lipengju on 2019-10-19.
//

#include <iostream>
using namespace std;

template <class E>
class Node{
    E value;

public:
    Node(E value){
        this->value=value;
    }

    Node(Node &node) {
        this->value=node.value;
    }

    Node<E> *next;
};


template <class E>
class LinkedList{


private:
    //头指针
    Node<E> head;
    //尾指针
    Node<E> currentNode =head;

public:

    LinkedList(Node<E> head) : head(head) {
    }

    /**
     * 添加元素
     * @param e
     */
     void push(E e){
       Node<E> node = new Node<E>(e);
       currentNode.next=node;
       currentNode=node;
     }

     void forEach(){

     }
     ~LinkedList() {}
};

void testLinkedList(){
    LinkedList<int> list = new LinkedList<int>(Node<E>(E()));
    list.push(1);
}




int main(){

   testLinkedList();
}

