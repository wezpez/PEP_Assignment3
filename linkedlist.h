#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>
#include <initializer_list>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

template <class T>
class LinkedList {

private:
    Node<T> * head;
    Node<T> * tail;
    int count;

public:

    LinkedList<T>()
            : head(nullptr), tail(nullptr), count(0) {}


    LinkedList<T>(std::initializer_list<T> list)
            : head(nullptr), tail(nullptr), count(0)
            {
                for(auto & l : list)
                {
                    push_back(l);
                }
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

        NodeIterator<T> iterator = NodeIterator<T>(head);

        LinkedList<T> tempList = LinkedList<T>();
        for (int i = 0; i < count; i++){
            tempList.push_front(iterator.current -> data);
            ++iterator;
        }

        head = tempList.head;
        tail = tempList.tail;

    }

    //inserting a new node into the linked list
    NodeIterator<T> insert(NodeIterator<T> insertPosition, T insertNode){

        count++;

        Node<T> * newNode = new Node<T>(insertNode);

        newNode->next = insertPosition.getCurrent();
        newNode->previous = insertPosition.getCurrent()->previous;

        insertPosition.getCurrent()->previous = newNode;

        if (insertPosition.getCurrent() == head){
            head = newNode;
            --insertPosition;
            return insertPosition;
        }

        --insertPosition;
        --insertPosition;

        insertPosition.getCurrent()->next = newNode;

        ++insertPosition;

        return insertPosition;
    }

    NodeIterator<T> erase(NodeIterator<T> erasePosition){

        count--;

        if (erasePosition.getCurrent() == head){
            Node<T>* deleteNode = erasePosition.getCurrent();

            ++erasePosition;
            erasePosition.getCurrent()->previous = nullptr;
            head = erasePosition.getCurrent();

            delete deleteNode;
            return erasePosition;
        }
        else if (erasePosition.getCurrent() == tail){
            Node<T>* deleteNode = erasePosition.getCurrent();

            --erasePosition;
            erasePosition.getCurrent()->next = nullptr;
            tail = erasePosition.getCurrent();

            delete deleteNode;
            return erasePosition;
        }
        else {
            NodeIterator<T> tempPosition = NodeIterator<T>(erasePosition.getCurrent()->previous);

            tempPosition.getCurrent()->next = erasePosition.getCurrent()->next;
            ++tempPosition;
            tempPosition.getCurrent()->previous = erasePosition.getCurrent()->previous;

            delete erasePosition.getCurrent();
            return tempPosition;

        }
    }


};




// do not edit below this line

#endif
