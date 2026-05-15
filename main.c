#include <stdio.h>
#include <stdint.h>

extern uint64_t asmpow(uint64_t x, uint64_t n);

int main()
{
    uint64_t val = asmpow(2,10);
    printf("2^10 = %lu\n", val);
    return 0;
}