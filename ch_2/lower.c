#include <stdio.h>

// EX. 2-10
char* lower(char* s) {
  int i;
  for (i = 0; s[i] != '\0'; ++i) {
    s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] + 'a' - 'A') : s[i];
  }

  return s;
}

int main(void) {
  char s[] = "heLlo woRlD";
  char* x = lower(s);
  printf("%s\n", x);

  return 0;
}
