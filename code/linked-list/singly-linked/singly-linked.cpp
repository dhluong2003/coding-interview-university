#include "singly-linked.h"

// template <class T>
bool LinkedList::empty() const{
    if (head==nullptr){
            return true;
        } else{
            return false;
        }
}

int LinkedList::size() const { 
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

int LinkedList::value_at(int i) const {
        node* current=head;
        int sz = size();
        // int position=0;
        if (i >= sz){
            throw std::range_error("input value larger than list size, exiting\n");
        }
        for (int a = 0; a < i; a++){
            if (not current){
                break;
            }
            current = current->getNext();
        }
        return current->getData();
}

void LinkedList::push_front(int value){
        // create new node
        node* newNode = new node;
        newNode->setData(value);
        newNode->setNext(nullptr);

        // if list is empty, have the head pointer point at the new node
        if (head==nullptr){
            head=newNode;
        }
        
        // if list is not empty, have the new node's next pointer point at the 
        else {
            newNode->setNext(head);
            head=newNode;
        }
    }

void LinkedList::pop_front(){
        node* temp = head;
        if (head==nullptr){
            throw std::runtime_error("cannot remove items when list is empty\n");
        }
        printf("removing value: %d\n", temp->getData());
        head = head->getNext();
        delete temp;
    }

void LinkedList::push_back(int value){
        node* newNode = new node;
        newNode->setNext(nullptr);
        newNode->setData(value);

        int sz = size() - 1;

        node* current=head;

        for (int i = 0; i < sz; ++i){
            current = current->getNext();
        }

        current->setNext(newNode);
    }

void LinkedList::pop_back(){
        node* current=head;
        node* tmp=head->getNext();

        if (head==nullptr){
            throw std::runtime_error("cannot remove elements when list is empty\n");
        }

        while(tmp->getNext() != nullptr){
            current = current->getNext();
            tmp = tmp->getNext();
        }
        printf("removing value: %d\n", tmp->getData());
        current->setNext(nullptr);
        delete tmp;

    }

    int LinkedList::getFrontElement() const {
        return head->getData();
    }

    int LinkedList::getBackElement() const {
        node* current=head;

        while (current != nullptr){
            current = current->getNext();
        }
        return current->getData();
    }

    void LinkedList::insert(int index, int value){
        node* current=head;
        
        for (int i = 0; i < index-1; i++){
            current = current->getNext();
        }
        node* next = current->getNext();

        node* newNode = new node;
        newNode->setData(value);
        newNode->setNext(nullptr);

        newNode->setNext(next);
        current->setNext(newNode);
    }

    void LinkedList::erase(int index){
        node* prev=head;

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

    void LinkedList::remove_value(int val){
        node *current = head;
        node *prev = nullptr;
        while (current->getData() != val){
            prev = current;
            current = current->getNext();
        }
        printf("\ncurrent values for prev & current: %d \t %d", prev->getData(), current->getData());
        prev->setNext(prev->getNext()->getNext());
        current->setNext(nullptr);

        delete current;
    }

    int LinkedList::value_n_from_end(int n){
        node* current=head;
        int sz = (size()-n);
        for (int i = 0; i < sz ; i++){
            current = current->getNext();
        }
        return current->getData();
    }

    void LinkedList::reverse(){ // iterative
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
    void LinkedList::print_list(){
        node* current=head;
        while(current!=nullptr){
            printf("%d ", current->getData());
            current=current->getNext();
        }
    }