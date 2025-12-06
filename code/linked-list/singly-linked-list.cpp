#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

class node{
    public:
        int data;
        struct node *next;
};


class LinkedList{
    node* head;

    public:

    // inits a blank singly-linked list
    LinkedList(){
        head=nullptr;
    }

    // check if linked list is empty

    bool empty(){
        if (head==nullptr){
            return true;
        } else{
            return false;
        }
    }

    // start at head pointer, continuously track what its next pointer is, if null, break and print number of elements
    int size() const { 
        node* current=head;
        int position=0;
        while(current){
            position++;
            current=current->next;

            if (not current){
                break;
            }
        }
        return position;
    }

    // get value at index i
    int value_at(int i) const {
        node* current=head;
        // int position=0;
        if (i >= size()){
            throw std::range_error("input value larger than list size, exiting\n");
        }
        for (int a = 0; a < i; a++){
            if (not current){
                break;
            }
            current = current->next;
        }
        return current->data;
    }

    // add value at the front of the list

    void push_front(int value){
        // create new node
        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        // if list is empty, have the head pointer point at the new node
        if (head==nullptr){
            head=newNode;
        }
        
        // if list is not empty, have the new node's next pointer point at the 
        else {
            newNode->next=head;
            head=newNode;
        }
    }

    void pop_front(){
        node* temp = head;
        if (head==nullptr){
            throw std::runtime_error("cannot remove items when list is empty\n");
        }
        printf("removing value: %d\n", temp->data);
        head = head->next;
        delete temp;
    }

    void push_back(int value){
        node* newNode = new node;
        newNode->next = nullptr;

        
    }
};

int main(){
    LinkedList test;

    bool empty = test.empty();
    printf("is list empty? (1 if yes, 0 if not): %d\n\n", empty);

    int listSize = test.size();
    printf("there are %d data elements in the list\n", listSize);
    
    test.push_front(5);
    test.push_front(3);
    test.push_front(98);
    
    listSize = test.size();
    printf("there are %d data elements in the list\n", listSize);

    int v = test.value_at(0);
    printf("value at specified index: %d\n", v);
    
    test.pop_front();
    // test.pop_front();
    // test.pop_front();
    // test.pop_front();
    v = test.value_at(0);
    printf("value at specified index: %d\n", v);
    
    
}
// linked_list;