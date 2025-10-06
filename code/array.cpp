#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

class Vector
{
    int* data;
    int size;
    int capacity;

    Vector(int vecCapacity)
        :size{0},capacity{16 ? vecCapacity <= 16 : next_pow_of_2(vecCapacity)} // round up to next power of 2 if vecCapacity > 16
    {
        data = new int[capacity];
    }

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
};

int main()
{

}