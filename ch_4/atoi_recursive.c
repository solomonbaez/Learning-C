#include <stdio.h>

void atoi_recursive(int n) {
  int sign = 1;

  if (n < 0) {
    sign = -1;
    n *= sign;
  }

  if (n / 10) {
    atoi_recursive(n / 10);
  }

  putchar(n % 10 + '0');
}

int main(void) {
  atoi_recursive(10110);
  putchar('\n');

  return 0;
}
