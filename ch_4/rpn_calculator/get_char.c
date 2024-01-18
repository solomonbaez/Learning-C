#include <stdio.h>
#include "calculator.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int b_i = 0;

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
