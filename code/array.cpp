#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

class Vector
{
    int* data;
    int size;
    int capacity;

    public:
    Vector(uint64_t vecCapacity)
        :size{0},capacity{(vecCapacity <= 16) ? 16 : next_pow_of_2(vecCapacity)} // round up to next power of 2 if vecCapacity > 16
    {
        data = new int[capacity];
        printf("created new vector w/ size of: %lld", capacity);
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
    Vector a = Vector(17);
}