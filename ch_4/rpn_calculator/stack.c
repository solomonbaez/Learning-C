#include <stdio.h>
#define MAXVAL 100

double stack[MAXVAL];
int s_i = 0;

void push(double n) {
  if (s_i < MAXVAL) {
    stack[s_i++] = n;
  } else {
    printf("error: stack full, cannot push %g\n", n);
  }
}

double pop(void) {
  if (s_i > 0) {
    return stack[--s_i];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}
