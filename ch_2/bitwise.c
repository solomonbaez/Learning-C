#include <stdio.h>

int getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & (~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned mask_l = ~0 << (p + 1);
  unsigned mask_r  = ~(~0 << (p + 1 - n));
  unsigned mask = mask_l | mask_r;

  return x & mask | ((y & ~(~0 << n)) << (p + 1 - n));
}

unsigned invbits(unsigned x, int p, int n) {
  unsigned mask_l = ~0 << (p + 1);
  unsigned mask_r = ~(~0 << (p + 1 - n));
  unsigned mask = mask_l | mask_r;

  return (x & mask) & ~(x & ~mask);
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

  return 0;
}
