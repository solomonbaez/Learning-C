#include <stdio.h>

int getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & (~0 << n);
}

// EX. 2-6
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned mask_l = ~0 << (p + 1);
  unsigned mask_r  = ~(~0 << (p + 1 - n));
  unsigned mask = mask_l | mask_r;

  return x & mask | ((y & ~(~0 << n)) << (p + 1 - n));
}

// EX. 2-7 -> optimized
unsigned invbits(unsigned x, int p, int n) {
  unsigned mask = ~(~0 << n) << (p + 1 - n);

  return x ^ mask;
}

// EX. 2-9
// In two's compliment, a negative number -x == (~x + 1)
// x &= (x - 1) deletes the rightmost bit of x
int bitcount(unsigned x) {
  int b = 0;
  while (x != 0) {
    ++b;
    x &= (x - 1);
  }

  return b;
}

int main(void) {
  unsigned i = 13;
  int p = 3;
  int n = 2;
  unsigned j = 10;

  unsigned k = setbits(i, p, n, j);
  printf("setbits(%u, %d, %d, %u) = %u\n", i, p, n, j, k);

  unsigned l = invbits(i, p, n);
  printf("invbits(%u, %d, %d) = %u\n", i, p, n, l);

  int m = bitcount(i);
  printf("bitcount(%u) = %d\n", i, m);

  return 0;
}
