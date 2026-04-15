// #include <stdio.h>
// #include <stdexcept>

#ifndef STACK_IMPL_H
#define STACK_IMPL_H

namespace stack{
template <class T>

class Stack{
    private:
        class Node {
            T data;
            Node *next;

        public:
        Node(const T& dt, Node* nxt=nullptr): next(nxt), data(dt){}
        Node(): data(), next(nullptr){} // default constructor
                
        void setNext(Node *node) { next = node; }
        Node* getNext() const { return next; }

        void setData(const T& value) { data = value; }
        const T& getData() const { return data; }
        };
    Node* head;

    public:
        Stack(): head(nullptr){};
        ~Stack();
        Stack(const Stack &) = delete;
        Stack &operator=(const Stack &) = delete; // do not permit copying

        void push(T value);
        void pop();
        int size() const;
        void print() const;
        bool isEmpty() const;
        T getTopElement() const;
        

};

}

#endif
