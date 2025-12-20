#include <iostream>
#include <stdexcept>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace linked_list{
template <class T>

class LinkedList{
    private:
        class node{
            T data;
            node<T> *next;

        public:
            const T getData()  {
                return data;
            }
            node<T> *getNext() {
                return next;
            }
            void setData(const T value){
                data = value;
            }
            void setNext(node<T> *node){
                next = node;
            }
        };
    node<T> *head;

    public:

    LinkedList(){
        head=nullptr;
    }
    ~LinkedList(); // destructor

    bool empty() const; // 1 if LL empty, 0 if not

    int size() const; // get size of linked list, 0 if empty

    T value_at(int index) const; // get value at specified index

    void push_front(T value); // insert value to front of list, push other elements back 

    void pop_front(); // remove frontmost element, move others forward

    void push_back(T value); // insert value to end of list

    void pop_back(); // remove value from end of list, return removed value

    T getFrontElement() const; // get head element

    T getBackElement() const; // get rearmost element

    void insert(int index, T value); // insert element at specified index with specified value

    void erase(int index); // remove element at specified index, move others behind it forward

    void remove_value(T val); // remove 1st instance of specified value

    T value_n_from_end(int n) const; // get nth element from end of list

    void reverse(); // reverse the list, iterative version

    void print_list(); // prints the list

};
}
#endif