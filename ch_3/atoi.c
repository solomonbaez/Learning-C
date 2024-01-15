#include <stdio.h>
#include <ctype.h>

int atoi(char s[]) {
  int i, sum;

  for (i = 0; s[i] == ' '; ++i);

  int sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+') {
    ++i;
  }

  for (sum = 0; isdigit(s[i]); ++i) {
    sum = 10 * sum + (s[i] - '0');
  }

  return sign * sum;
}

int main(void) {
  char s[] = " -1234";
  int res = atoi(s);
  printf("original: %s, atoi: %d\n", s, res);

  return 0;
}
