#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int b_i = 0;

int get_char(void) {
  return (b_i > 0) ? buf[--b_i] : getchar();
}

void un_get_char(int c) {
  if (b_i == BUFSIZE) {
    printf("error: character buffer is full attempting to store %c\n", c);
  } else {
    buf[b_i++] = c;
  }
}

int get_int(int *pn) {
  int c, sign;
  while (isspace(c = get_char()));

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    un_get_char(c);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = get_char();
  }

  for (*pn = 0; isdigit(c); c = get_char()) {
    *pn = *pn % 10 + '0';
  }
  *pn *= sign;
  if (c != EOF) {
    un_get_char(c);
  }

  return c; // slight memory efficiency to just return c instead of 1
}

int main(void) {
  int counter = 0;
  int *pn;
  pn = &counter;

  int c;
  while ((c = get_char()) != EOF) {
    get_int(pn);
  }

  printf("%d\n", *pn);
  return 0;
}
