#include <stdio.h>

char* itob(int n, char s[], int base) {
  int range = 1;
  while (range < n) { range *= base; }

  int i;
  for (i = 0; range > 1; ++i) {
    if (n >= range) {
      s[i] = '1';
      n -= range;
    } else {
      s[i] = '0';
    }

    range /= base;
  }

  s[i] = (n >= 1) ? '1' : '0';
  return s;
}

int main(void) {
  char s[1000];
  int n = 11;
  int base = 2;
  char* n_b = itob(n, s, base);
  printf("integer: %d, base_%d: %s\n", n, base, n_b);
}
