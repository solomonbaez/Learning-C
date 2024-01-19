#include <stdio.h>

void itoa_recursive(int n, int i, char s[])  {
  void reverse_recursive(int, int, char []);

  s[i] = n % 10 + '0';

  if (n / 10) {
    itoa_recursive(n / 10, ++i, s);
  } else {
    reverse_recursive(0, i, s);
  }
}

void reverse_recursive(int i, int j, char s[]) {
  char tmp = s[i];
  s[i] = s[j];
  s[j] = tmp;

  if (i < j) { reverse_recursive(++i, --j, s); }
}

#define MAXCHAR 1000
int main(void) {
  char s[MAXCHAR];

  itoa_recursive(251, 0, s);
  printf("itoa: %s\n", s);
}
