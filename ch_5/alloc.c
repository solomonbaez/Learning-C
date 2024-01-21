#include <stdio.h>

#define ALLOCSIZE 1000

static char alloc_buf[ALLOCSIZE];
static char *alloc_cp = alloc_buf; // first position in alloc

char *alloc(int n) {
  // check for space
  if (alloc_buf + ALLOCSIZE - alloc_cp >= n) {
    alloc_cp += n; // increment alloc
    return alloc_cp - n;
  } else {
    return 0;
  }
}

void alloc_free(char *p) {
  if (p >= alloc_buf && p < alloc_buf + ALLOCSIZE) {
    alloc_cp = p;
  }
}

int main(void) {
  return 0;
}
