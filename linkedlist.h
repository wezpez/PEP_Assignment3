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
/*
        NodeIterator<T> iterator = NodeIterator<T>(head);



        LinkedList<T> tempList = LinkedList<T>();
        for (int i = 0; i < count; i++){
            tempList.push_front(iterator.current -> data);
            ++iterator;
        }

        head = tempList.head;
        tail = tempList.tail;






        for (int i = 1; i < count; i++){
            Node<T> * temp = iterator.current -> next;
            iterator.current -> next = iterator.current -> previous;
            iterator.current -> previous = temp;

            if (iterator.current != nullptr){
                iterator.current = iterator.current -> previous;
            }

        }



        Node<T> * temp = head;
        head = tail;
        tail = temp;
*/

    }

};




// do not edit below this line

#endif
