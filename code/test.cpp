#include <iostream>
#include <cstdint>

uint64_t next_pow2m1(uint64_t x) {
//   x |= x>>1;
// 	x |= x>>2;
// 	x |= x>>4;
// 	x |= x>>8;
// 	x |= x>>16;
// 	x |= x>>32;
//   return x;
    x--;
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        x++;
    return x;
}

int main(){
    uint64_t t = next_pow2m1(65);
    printf("number: %lld", t);
}