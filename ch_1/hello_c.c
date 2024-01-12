#include <stdio.h>

/*test comment ;)*/
void F_C_Table() {
  float f, c;
  for (f = 400; f >= 0; f -= 20) {
    c = (5.0/9.0) * (f - 32.0);
    printf("%3.2f \t %6.2f \n", f, c);
  }
}

int main() {
  printf("hello, world\n");
  F_C_Table();
}
