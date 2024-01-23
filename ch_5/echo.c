#include <stdio.h>

int main(int arg_c, char *arg_v[]) {
  while (--arg_c) {
    printf((arg_c > 1) ? "%s " : "%s", *++arg_v);
  }
  printf("\n");
  return 0;
}
