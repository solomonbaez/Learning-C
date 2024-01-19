#include <stdio.h>

void itoa_recursive(int n, int i, char s[])  {
  void reverse(int, char []);

  s[i] = n % 10 + '0';

  if (n / 10) {
    itoa_recursive(n / 10, ++i, s);
  } else {
    reverse(i, s);
  }
}

void reverse(int length, char s[]) {
  int i, j;
  for (i = 0, j = length; i < j; i++, j--) {
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
  }
}

#define MAXCHAR 1000
int main(void) {
  char s[MAXCHAR];

  itoa_recursive(221, 0, s);
  printf("itoa: %s\n", s);
}
