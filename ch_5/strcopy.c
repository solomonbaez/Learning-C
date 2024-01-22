#include <stdio.h>

void str_copy(char *from, char *to) {
  // termination at 0 ~= '\0'
  while ((*to++ = *from++));
}

int main(void) {
  char *from = "hello, world";
  char to[13];

  str_copy(from, to);
  printf("original: %s, copy: %s\n", from, to);
  return 0;
}
