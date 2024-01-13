#include <stdio.h>

/* const definitions */
#define LOWER 0
#define UPPER 400
#define DELTA 20

void F_C_Table() {
  float f, c;
  for (f = UPPER; f >= LOWER; f -= DELTA) {
    c = (5.0/9.0) * (f - 32.0);
    printf("%3.2f \t %6.2f \n", f, c);
  }
}

int main() {
  printf("hello, world\n");
  F_C_Table();
}
