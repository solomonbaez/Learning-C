#include <stdio.h>
#include <ctype.h>
#include "calculator.h"

int get_char(void);
void un_get_char(int);

int get_op(char s[]) {
  int i, c;
  while ((s[0] = c = get_char()) == ' ' || c == '\t');

  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c; // NaN
  }

  i = 0;
  if (isdigit(c)) {
    while (isdigit((s[++i] = c = get_char())));
  }

  if (c == '.') {
    while (isdigit((s[++i] = c = get_char())));
  }

  s[i] = '\0';
  if (c != EOF) {
    un_get_char(c);
  }

  return NUMBER;
}
