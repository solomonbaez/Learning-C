#include <stdio.h>

char* itoa(int n, char s[]) {
  int sign;
  if ((sign = n) < 0)
  {
    n *= -1;
  }

  int i = 0;
  do
  {
    s[i++] = n % 10 + '0';
  }
  while ((n /= 10) > 0);

  if (sign < 0)
  {
    s[i] = '-';
  }
  printf("%s\n", s);

  for (int j = 0; j < i; ++j)
  {
    char c = s[i];
    s[i--] = s[j];
    s[j] = c;
  }

  return s;
}

int main(void) {
  char s[4];
  int n = -100;
  char* itoa_s = itoa(n, s);
  printf("original: %d, itoa: %s\n", n, itoa_s);

  return 0;
}
