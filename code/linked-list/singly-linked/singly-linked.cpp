#include "singly-linked.h"

namespace linked_list{


template <class T>
LinkedList<T>::~LinkedList(){
    node *current = head;
    node *next = nullptr;

    while (current){
        next = current->getNext();
        delete current;
        current = next;
    }
}
template <class T>
bool LinkedList<T>::empty() const{
    if (head==nullptr){
            return true;
        } else{
            return false;
        }
}

template <class T>
int LinkedList<T>::size() const { 
        node *current=head;
        int position=0;
        while(current){
            position++;
            current=current->getNext();

            if (not current){
                break;
            }
        }
        return position;
    }

template <class T>
T LinkedList<T>::value_at(int index) const {
        node* current=head;
        int sz = size();
        // int position=0;
        if (index >= sz or index < 0){
            throw std::range_error("input value outsize allowed range, exiting\n");
        }
        for (int a = 0; a < index; a++){
            if (not current){
                break;
            }
            current = current->getNext();
        }
        return current->getData();
}

template <class T>
void LinkedList<T>::push_front(T value){
        // create new node
        node* newNode = new node(value, nullptr);
        // newNode->setData(value);
        // newNode->setNext(nullptr);

        // empty list -> set head to new node
        if (head==nullptr)
        {
            head=newNode;
        }
        else if (head->getNext() == nullptr) // 1-element list
        {
            newNode->setNext(head);
            head->setNext(newNode);
        }
        
        // if list is not empty, have the new node's next pointer point at the 
        else {
            newNode->setNext(head);
            head=newNode;
        }
    }
template <class T>
void LinkedList<T>::pop_front(){
        node* temp = head;
        // int sz = size();
        if (head==nullptr){
            throw std::runtime_error("cannot remove items when list is empty\n");
        }
        head = head->getNext();
        delete temp;
    }
template <class T>
void LinkedList<T>::push_back(T value){
        node* newNode = new node(value, nullptr);
        int sz = size() - 1;
        node* current=head;

        if(head == nullptr){
            head = newNode;
        }
        else {
            for (int i = 0; i < sz; ++i){
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }
template <class T>
void LinkedList<T>::pop_back(){
    if (head==nullptr){ // list is empty
        throw std::runtime_error("cannot remove elements when list is empty\n");
    }
    node* current=head; // move here after we confirm head exists
        
    if (head->getNext() == nullptr){ // single element list
        head = nullptr;
        delete current;
    }
    
    else
    {
        node* tmp=head->getNext();
        while(tmp->getNext() != nullptr)
        {
            current = current->getNext();
            tmp = tmp->getNext();
        }
        current->setNext(nullptr);
        delete tmp;
    }
}


template <class T>
T LinkedList<T>::getFrontElement() const {
        return head->getData();
    }

template <class T>
T LinkedList<T>::getBackElement() const {
        node* current=head;

        while (current->getNext() != nullptr){
            current = current->getNext();
        }
        return current->getData();
    }

template <class T>
void LinkedList<T>::insert(int index, T value){
        node* current=head;
        int sz = size();

        
        node* newNode = new node(value, nullptr);
        if (index < 0 or index >= sz){
            throw std::range_error("illegal index value (cannot be < 0 or larger than list size, minus 1)");
        }
        
        if (index == 0){ // if inserting at head
            newNode->setNext(head);
            head = newNode;
            return;
        }
        
        for (int i = 0; i < index-1; i++){
            current = current->getNext();
        }
        node* next = current->getNext();
        
        
        newNode->setNext(next);
        current->setNext(newNode);
    }
    
    template <class T>
    void LinkedList<T>::erase(int index){
        node* prev=head;
        int sz = size();
        
        if (index < 0 or index >= sz){
            throw std::range_error("illegal index value (cannot be < 0 or larger than list size, minus 1)");
        }

        //if list is empty throw an exception
        if (head == nullptr){
            throw std::range_error("cannot delete specified index when list is empty");
        }
        if (index == 0){ // removing head
            head = head->getNext();
            delete prev;
            return;
        }

        for (int i = 0; i < index-1; i++){
            prev = prev->getNext();
        }
        node* nodeToDelete = prev->getNext();
        node* aft = nodeToDelete->getNext();

        printf("\ndeleting element %d at index %d", nodeToDelete->getData(), index);

        nodeToDelete->setNext(nullptr);
        prev->setNext(aft);

        delete nodeToDelete;
    }

template <class T>
void LinkedList<T>::remove_value(T val){ // at the moment silently does nothing if specified value doesn't exist
        node *current = head;
        node *prev = nullptr;
        
        while (current){                                // check if list is empty
            if (current->getData() == val){
                if (prev == nullptr){                   // check if removing the head
                    head = current->getNext();
                } else{
                    prev->setNext(current->getNext());
                }
            delete current;
            break;
            }
        prev = current;
        current = current->getNext();
        }
}

template <class T>
T LinkedList<T>::value_n_from_end(int n) const{
        if (n <= 0)
        {
            throw std::range_error("specified index value must be a nonzero positive integer\n");
        }

        if (not head)
        {
            throw std::logic_error("empty linked list, nothing to show\n");
        }

        node* fwd=head;
        // node* bck=nullptr;

        // if condition before moving fwd forward or else it can error for 1-element lists and n = 1 (should return the only element)
        for (int i = 0; i < n; i++){
            if (fwd == nullptr){
                throw std::range_error("specified index value is larger than list size\n");
            }
            fwd = fwd->getNext();
        }
        node* bck = head;
        while (fwd != nullptr){
            fwd = fwd->getNext();
            bck = bck->getNext();
        }
        return bck->getData();
}

template <class T>
void LinkedList<T>::reverse(){ // iterative
        node *current = head, *prev = nullptr, *nxt;
        
        while(current!=nullptr){
            nxt = current->getNext();
            current->setNext(prev);
            prev = current;
            current = nxt;
        }
        // return prev;
        head = prev;
    }

template <class T>
void LinkedList<T>::print_list() const {
        node* current=head;
        while(current!=nullptr){
            std::cout << current->getData() << " ";
            current=current->getNext();
        }
    }
}