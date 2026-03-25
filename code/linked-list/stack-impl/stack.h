#include <stdio.h>

#ifndef STACK_IMPL_H
#define STACK_IMPL_H

namespace stack{
template <class T>

class Stack{
    private:
        class Node {
            private:
                T data;
                Node *next;

            public:
                Node (Node *nxt, T dt): next(nxt), data(dt){}
                Node(): next(nullptr), data(){} // default constructor
                
                void setNext(Node *node) { next = node; }
                Node* getNext() const { return next; }

                void setData(const T& value) { data = value; }
                const T& getData() const { return data; }
        }
    Node* head;

    public:
        Stack(): head(nullptr){};
        ~Stack(){};
        Stack(const Stack &) = delete;
        Stack &operator=(const Stack &) = delete; // do not permit copying

        void push(T value);
        void pop(T value);

};

}

#endif