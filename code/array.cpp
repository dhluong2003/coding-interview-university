#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <stdexcept>
#include <iostream>

using namespace std;

class Vector
{
    int* data;
    uint64_t vSize;
    uint64_t vCapacity;

    public:
        uint64_t next_pow_of_2(uint64_t t){
            t--;
            t |= t >> 1;
            t |= t >> 2;
            t |= t >> 4;
            t |= t >> 8;
            t |= t >> 16;
            t++;
        return t;
        }
        int size(){
            return vSize;
        }

        int capacity(){
            return vCapacity;
        }

        bool is_empty(){
            return ((vSize == 0)) ? true : false;
        }

        int at_index(int i){
            if (i < 0 || i >= vCapacity){
                throw std::out_of_range("out of range\n");
            }
            return *(data + i);
        }

        void push(int value){
            if (vSize == vCapacity){
                resize(2); // double array capacity
            }
            *(data+vSize) = value;
            vSize++;
        }

        void insert(int index, int item){
            if (vSize == vCapacity){
                resize(2.0);
            }

            for (int i = vSize - 1; i >= index; i--){
                *(data + i + 1) = *(data + i); // shift elements in x direction -> begin from x direction to the opposite direction
            }

            *(data + index) = item;
            vSize++;
        }

        void pop(){
            if (vSize == 0){
                throw std::length_error("empty vector");
            }
            vSize--;
            if ( (vSize / vCapacity) == 0.25 ){
                resize(0.5);
            }
        }

        void prepend(int item){
            if (vSize == vCapacity){
                resize(2.0);
            }

            for (int i = vSize - 1; i >= 0; i--){
                *(data + i + 1) = *(data + i); // shift elements in x direction -> begin from x direction to the opposite direction
            }

            *data = item;
            vSize++;
        }
        void print(){
            for (int i = 0; i < vSize; i++){
                cout << *(data + i) << " ";
            }
        }

        Vector(uint64_t vecCapacity)
        :vSize{0},vCapacity{(vecCapacity <= 16) ? 16 : next_pow_of_2(vecCapacity)} // round up to next power of 2 if vecCapacity > 16
        {
            data = new int[vCapacity];
            printf("created new vector w/ size of: %lld\n", vCapacity);
        }
    private:
    void resize(double scalingFactor){
        int new_capacity = static_cast<int>(scalingFactor * vCapacity);
        int* new_vec = new int[new_capacity]; // make new vector

        for (int i = 0; i < vSize; i++){
            *(new_vec+i) = *(data+i); // copy data from old vector to new
        }

        delete[] data;
        data = new_vec;
        vCapacity = new_capacity;
    }
    
};

int main()
{
    Vector a = Vector(17);
    printf("size: %d\n", a.size());
    printf("capacity: %d\n", a.capacity());
    // printf("is empty? (1 = true, 0 = false): %d\n", a.is_empty());
    
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.print();
    
    printf("\nvalue at index 1: %d\n", a.at_index(1));
    // printf("\nvalue at index 55: %d\n", a.at_index(55));
    a.insert(1, 38);
    a.print();

    cout << "\n";
    a.prepend(45);
    a.print();

}