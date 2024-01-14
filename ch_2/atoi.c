#include <stdio.h>

// digits string -> numeric eq.
int atoi(char s[]) {
  int i;

  int n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
  }

  return n;
}

int lower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  }

  return c;
}

char* str_lower(char* s) {
  int i;
  for (i = 0; s[i] != '\0'; ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = lower(s[i]);
    }
  }

  return s;
}

int main() {
  int x = atoi("1234");
  printf("%d\n", x);

  char y = lower('C');
  printf("%c\n", y);

  char s[10] = "hellO, WorlD";
  char* z = str_lower(s);
  printf("%s\n", z);

  return 0;
}
