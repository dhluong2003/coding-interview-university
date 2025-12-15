#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

using namespace std;

class node{
    public:
        int data;
        node *next;
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
        newNode->data = value;

        node* current=head;

        for (int i = 0; i < size()-1; ++i){
            current = current->next;
        }

        current->next = newNode;
    }

    void pop_back(){
        node* current=head;
        node* tmp=head->next;

        if (head==nullptr){
            throw std::runtime_error("cannot remove elements when list is empty\n");
        }

        while(tmp->next != nullptr){
            current = current->next;
            tmp = tmp->next;
        }
        printf("removing value: %d\n", tmp->data);
        current->next = nullptr;
        delete tmp;

    }

    int getFrontElement() const {
        return head->data;
    }

    int getBackElement() const {
        node* current=head;

        while (current != nullptr){
            current = current->next;
        }
        return current->data;
    }

    void insert(int index, int value){
        node* current=head;
        
        for (int i = 0; i < index-1; i++){
            current = current->next;
        }
        node* next = current->next;

        node* newNode = new node;
        newNode->data = value;
        newNode->next = nullptr;

        newNode->next = next;
        current->next = newNode;
    }

    void erase(int index){
        node* prev=head;

        for (int i = 0; i < index-1; i++){
            prev = prev->next;
        }
        node* nodeToDelete = prev->next;
        node* aft = nodeToDelete->next;

        printf("\ndeleting element %d at index %d", nodeToDelete->data, index);

        nodeToDelete->next = nullptr;
        prev->next = aft;

        delete nodeToDelete;
    }

    int value_n_from_end(int n){
        node* current=head;
        int sz = (size()-n);
        for (int i = 0; i < sz ; i++){
            current = current->next;
        }
        return current->data;
    }

    void reverse(){ // iterative
        node *current = head, *prev = nullptr, *nxt;
        // int sz = size();
        
        while(current!=nullptr){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        // return prev;
        head = prev;
    }

    void remove_value(int val){
        node *current = head;
    }
    void print_list(){
        node* current=head;
        while(current!=nullptr){
            printf("%d ", current->data);
            current=current->next;
        }
    }
};

int main(){
    LinkedList test;

    bool empty = test.empty();
    printf("is list empty? (1 if yes, 0 if not): %d\n\n", empty);

    int listSize = test.size();
    printf("there are %d data elements in the list\n", listSize);
    

    for (int i = 0; i <= 3; i++){
        test.push_front(i);
    }
    
    listSize = test.size();
    printf("there are %d data elements in the list\n", listSize);

    int v = test.value_at(0);
    printf("value at specified index: %d\n", v);
    
    test.pop_front();
    v = test.value_at(0);
    printf("value at specified index: %d\n", v);

    printf("current list: ");
    test.print_list();

    test.push_back(78);
    test.push_back(4891296);
    printf("\nnew list: ");
    test.print_list();

    printf("\nremoving rearmost element:");
    test.pop_back();
    printf("\nnew list: ");
    test.print_list();
    
    printf("\ninserting new element: 35 at index 3");
    test.insert(3, 35);
    printf("\nnew list: ");
    test.print_list();
    
    // printf("\ndeleting element at index 3");
    // test.erase(3);
    // printf("\nnew list: ");
    // test.print_list();
    
    printf("\nget 2nd element from end of list\n");
    v = test.value_n_from_end(4);
    printf("\n4th element from end of list: %d", v);

    printf("\nprinting current LL: ");
    test.print_list();
    printf("\nreversing linked list: ");
    test.reverse();
    cout << "\n";
    test.print_list();

}
// linked_list;