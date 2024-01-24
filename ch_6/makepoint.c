#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point point_1;
  struct point point_2;
};

struct point make_point(int x, int y) {
  struct point tmp;
  tmp.x = x;
  tmp.y = y;

  return tmp;
}

int main(void) {
  struct point add_points(struct rect);
  int in_rect(struct rect, struct point);
  struct rect canonical_rect(struct rect *r);

  struct rect screen;
  screen.point_1 = make_point(0, 0);
  screen.point_2 = make_point(10, 20);

  struct point added_points = add_points(screen);
  printf("added points: (%d, %d)\n", added_points.x, added_points.y);

  struct point random_point = { 0, -1 };
  printf("point: (%d, %d), %s within the screen\n", random_point.x, random_point.y, in_rect(screen, random_point) ? "is" : "is not");

  struct rect canonical_screen = canonical_rect(&screen);

  return 0;
}

struct point add_points(struct rect r) {
  r.point_1.x += r.point_2.x;
  r.point_1.y += r.point_2.y;

  return r.point_1;
}

int in_rect(struct rect r, struct point p) {
  return p.x <= r.point_2.x && p.x >= r.point_1.x && p.y <= r.point_2.y && p.y >= r.point_1.y;
}

#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct rect canonical_rect(struct rect *r) {
  struct rect tmp;

  tmp.point_1.x = min(r->point_1.x, r->point_2.x);
  tmp.point_1.y = min(r->point_1.y, r->point_2.y);
  tmp.point_2.x = max(r->point_1.x, r->point_2.x);
  tmp.point_2.y = max(r->point_1.x, r->point_2.x);

  return tmp;
}
