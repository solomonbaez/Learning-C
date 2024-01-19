#include <stdio.h>

void printd(int n) {
  int sign = 1;

  if (n < 0) {
    sign = -1;
    n *= sign;
  }

  if (n / 10) {
    printd(n / 10);
  }

  putchar(n % 10 + '0');
}

int main(void) {
  printd(10110);
  putchar('\n');

  return 0;
}
