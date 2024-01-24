#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point b_l_corner;
  struct point t_r_corner;
};

struct point make_point(int x, int y) {
  struct point tmp;
  tmp.x = x;
  tmp.y = y;

  return tmp;
}

int main(void) {
  struct point add_points(struct rectangle);

  struct rectangle screen;
  screen.b_l_corner = make_point(0, 0);
  screen.t_r_corner = make_point(10, 20);

  struct point added_points = add_points(screen);
  printf("added points: (%d, %d)\n", added_points.x, added_points.y);

  return 0;
}

struct point add_points(struct rectangle screen) {
  screen.b_l_corner.x += screen.t_r_corner.x;
  screen.b_l_corner.y += screen.t_r_corner.y;

  return screen.b_l_corner;
}
