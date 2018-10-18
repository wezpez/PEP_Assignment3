#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

template <class T>
class LinkedList {

private:
    Node<T> * head;
    Node<T> * tail;
    int count;

public:

    LinkedList<T>()
            :head(nullptr), tail(nullptr), count(0) {

    }

    void push_front(T nHead){

        Node<T> * newNode = new Node<T>(nHead);

        if (count != 0){
            head -> previous = newNode;
            newNode -> next = head;
            head = newNode;
        }
        else {
            head = newNode;
            tail = newNode;
        }

        count++;
    }

    T & front(){
        return head -> data;
    }

    void push_back(T nTail){

        Node<T> * newNode = new Node<T>(nTail);

        if (count != 0){
            tail -> next = newNode;
            newNode -> previous = tail;
            tail = newNode;
        }
        else {
            head = newNode;
            tail = newNode;
        }

        count++;
    }

    T & back(){
        return tail -> data;
    }

    int size(){
        return count;
    }

    NodeIterator<T> begin(){
        NodeIterator<T> newIterator = NodeIterator<T>(head);
        return newIterator;
    }

    NodeIterator<T> end(){
        NodeIterator<T> newIterator = NodeIterator<T>(tail -> next);
        return newIterator;
    }

    ~LinkedList(){
        for (int i = 0; i < count; i++){
            Node<T>* deleteNode = head;
            head = deleteNode -> next;
            delete deleteNode;
        }
        count = 0;
    }

    void reverse(){
        

      /*  NodeIterator<T> iterator = NodeIterator<T>(head);
        for (int i = 0; i < count - 1; i++){
            Node<T> * temp = iterator.getCurrent() -> next;
            iterator.getCurrent() -> next = iterator.getCurrent() -> previous;
            iterator.getCurrent() -> previous = temp;
            ++iterator;
        }
        Node<T> * temp = head;
        head = tail;
        tail = temp;*/
    }

};




// do not edit below this line

#endif
