//
// Created by pengju.li on 2019-10-30.
//

template<class T>
struct Node {
    // data members
    T element;
    Node<T> *next;

    // methods
    Node() {}

    Node(const T &element) { this->element = element; }

    Node(const T &element, Node <T> *next) {
        this->element = element;
        this->next = next;
    }
};
