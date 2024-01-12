#include <stdio.h>

/*test comment ;)*/
void F_C_Table() {
  float f, c;
  float lower, upper, delta;

  lower = 0;
  upper = 400;
  delta = 20;

  f = lower;
  while (f <= upper) {
    c = (5.0 / 9.0) * (f - 32.0);
    printf("%3.2f \t %6.2f \n", f, c);
    f += delta;
  }
}

int main() {
  printf("hello, world\n");
  F_C_Table();
}
