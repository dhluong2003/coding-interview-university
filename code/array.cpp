#include <stdio.h>
#include <stdlib.h>

class Vector
{
    int* data;
    int size;
    int capacity;

    Vector(int vecCapacity)
        :size{0},capacity{16 ? vecCapacity <= 16 : } // round up to next power of 2 if vecCapacity > 16
    {
        data = new int[capacity];
    }
};

int main()
{

}