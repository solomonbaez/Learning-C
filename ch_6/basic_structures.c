#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point first_point;
  struct point second_point;
};

int main(void) {
  struct point first_point = { 10, 20 };
  printf("point: (%d, %d)\n", first_point.x, first_point.y);

  struct point second_point = { 0, 0 };
  struct rectangle new_rectangle = { first_point, second_point };
  printf("point: (%d, %d)\n", new_rectangle.second_point.x, new_rectangle.second_point.y );

  return 0;
}
