#include "stack.h"
#include <stdexcept>

namespace stack{
    template <class T>
    Stack<T>::~Stack(){
        while(head){
            Node* next = head->getNext();
            delete head;
            head = next;
        }
    }

    template <class T>
    void Stack<T>::push(T value){
        Node* newNode = new Node(value, nullptr);

        // case: empty stack
        if (head == nullptr) { head->setNext(newNode); }

        // case: stack w/ at least 1 elmt
        else if (head->getNext() == nullptr) {
            newNode->setNext(head);
            head->setNext(newNode);
        }
    }

    template <class T>
    void Stack<T>::pop(){
        // case: empty stack - throw an error
        if (head == nullptr) {
            throw std::range_error("cannot pop an empty stack");
        }

        // case: stack w/ 1 elmt
        if (head->getNext() == nullptr){
            Node* tmp = head;
            head = nullptr;
            delete tmp;
        }

        // case: stack w/ 2 or more elmts
        else {
            Node* tmp = head;
            head->setNext(head->next)
            delete tmp;
        }
    }
}