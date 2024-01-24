#include <stdio.h>

struct point {
  int x;
  int y;
};

int main(void) {
  struct point new_point = { 10, 20 };
  printf("point: (%d, %d)\n", new_point.x, new_point.y);

  return 0;
}
