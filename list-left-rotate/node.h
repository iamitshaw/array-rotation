
/* Include Guard */

#ifndef _NODE_H_
#define _NODE_H_

#include "object.h"

template <typename T>
class Node {
    template <typename U>
    friend class SinglyLinkedList;

private:
    Object<T> object;
    Node<T>* next;
public:
    Node();
    explicit Node(T data);
    explicit Node(Object<T> object);
    void setObject(Object<T> object_value);
    Object<T> getObject();
    void setNext(Node<T> next_val);
    Node<T>* getNext();
    T getData();
    void setData(T data);

};

/* default constructor */
template<typename T>
Node<T>::Node() = default;

/* overloaded constructor */
template <typename T>
Node<T>::Node(T data) {
    object.data = data;
    next = {nullptr};
}

template<typename T>
Node<T>::Node(Object<T> object)
        : object{object}, next{nullptr}{

}

/* setters */
template<typename T>
void Node<T>::setObject(Object<T> object_value) {
    Node::object = object_value;
}

template<typename T>
void Node<T>::setNext(Node<T> next_val) {
    Node::next = next_val;
}

/* getter */
template<typename T>
Object<T> Node<T>::getObject() {
    return Node::object;
}

template<typename T>
Node<T> *Node<T>::getNext() {
    return Node::next;
}

template<typename T>
T Node<T>::getData() {
    return object.data;
}

template<typename T>
void Node<T>::setData(T data) {
    object.data = data;
}


#endif