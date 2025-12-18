#include <iostream>
#include <stdexcept>


// template <class T>

class LinkedList{
    private:
    class node{
        int data;
        node *next;

    public:
        int getData() const {
            return data;
        }
        node* getNext() {
            return next;
        }
        void setData(int value){
            data = value;
        }
        void setNext(node *node){
            next = node;
        }
    };
    node *head;

    public:

    LinkedList(){
        head=nullptr;
    }
    ~LinkedList(); // destructor

    bool empty() const; // 1 if LL empty, 0 if not

    int size() const; // get size of linked list, 0 if empty

    int value_at(int index) const; // get value at specified index

    void push_front(int value); // insert value to front of list, push other elements back 

    void pop_front(); // remove frontmost element, move others forward

    void push_back(int value); // insert value to end of list

    void pop_back(); // remove value from end of list, return removed value

    int getFrontElement() const; // get head element

    int getBackElement() const; // get rearmost element

    void insert(int index, int value); // insert element at specified index with specified value

    void erase(int index); // remove element at specified index, move others behind it forward

    void remove_value(int val); // remove 1st instance of specified value

    int value_n_from_end(int n); // get nth element from end of list

    void reverse(); // reverse the list, iterative version

    void print_list(); // prints the list

};