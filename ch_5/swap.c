#include <stdio.h>

void swap(int *px, int *py) {
  int tmp = *px;
  *px = *py;
  *py = tmp;
}

int main(void) {
  int x = 10;
  int y = 5;

  printf("original: x=%d, y=%d; ", x, y);

  swap(&x, &y);
  printf("swapped: x=%d, y=%d\n", x, y);
}
