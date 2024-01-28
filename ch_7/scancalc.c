#include <stdio.h>

int main(void) {
  float sum = 0, val = 0;

  while (scanf("%1f", &val) == 1) {
    printf("\t%.2f\n", sum += val);
  }

  return 0;
}
