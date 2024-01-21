#include <stdio.h>

int str_len(char *s) {
  int n;

  // note *s to access the data, s to increment the pointer
  for (n = 0; *s != '\0' ; s++) { ++n; }
  return n;
}

int main(void) {
  char s[] = "hello, world";
  printf("string: %s, length: %d\n", s, str_len(s));
}
