#include <stdio.h>

int str_end(char *p_1, char *p_2) {
  int len_1, len_2;
  len_1 = len_2 = 0;
  // find the end of each string
  while (*++p_1 != '\0') { ++len_1; };
  while (*++p_2 != '\0') { ++len_2; };

  if (len_1 < len_2) {
    return 0;
  }

  while (*--p_1 == *--p_2) {
    if (len_2-- == 0) {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  char *s_1 = "hello, world!";
  char *s_2 = "world!";

  printf("%s\n", ((str_end(s_1, s_2)) ? "true" : "false"));

  return 0;
}
