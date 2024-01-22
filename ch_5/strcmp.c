#include <stdio.h>

int str_cmp(char *p_1, char *p_2) {
  while (*p_1++ == *p_2++) {
    if (*p_1 == '\0' || *p_2 == '\0') { return 0; }
  }

  return *p_1 - *p_2;
}

int main(void) {
  char *p_1 = "hello, world";
  char *p_2 = "gloria invigilata";

  printf("%d\n", str_cmp(p_1, p_2));

  return 0;
}
