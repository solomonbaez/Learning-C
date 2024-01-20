#include <stdio.h>

#define swap(type, x, y) do { type tmp = x; x = y; y = tmp; } while(0)

int main(void) {
  int x = 10;
  int y = 1;

  int xs = x;
  int ys = y;

  swap(int, xs, ys);
  printf("original: %d, %d, swapped: %d, %d\n", x, y, xs, ys);

  return 0;
}
