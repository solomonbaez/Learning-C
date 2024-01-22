#include <stdio.h>

void str_cat(char *p_1, char *p_2) {
  while (*++p_1 != '\0');
  while ((*p_1++ = *p_2++) != '\0');
}

int main(void) {
  char s_1[100] = "Hello, world!";
  char *s_2 = " I'm BMO!";
  printf("original: %s, ", s_1);

  str_cat(s_1, s_2);
  printf("concatenated: %s\n", s_1);
}
