#ifndef NODE_H
#define NODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

template <class T>
class Node {

public:

    T data;
    Node<T> * next;
    Node<T> * previous;
    Node<T>(const T& d):data(d), next(nullptr), previous(nullptr) {}


};



template<typename T>
class NodeIterator {
  
private:
    
    Node<T> * current;
    
public:
    

    NodeIterator(Node<T> * currentIn)
        : current(currentIn) {        
    }

    T & operator*() {
        return current -> data;
    }


    void operator++() {
        current = current -> next;
    }

    bool operator==(NodeIterator & rhs) {
        if (current == rhs.current){
            return true;
        }
        else {
            return false;
        }

    }

    bool operator!=(NodeIterator & rhs) {
        if (current != rhs.current){
            return true;
        }
        else {
            return false;
        }

    }

    Node<T> * getCurrent(){
        return current;
    }

};

// do not edit below this line

#endif
