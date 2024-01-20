#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)

int main(void) {
  double x = 10;
  double y = 2;
  dprint(x/y);

  return 0;
}
