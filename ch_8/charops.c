#include <unistd.h>
#include <stdio.h>

int getChar(void) {
  char c;

  // unbuffered GET
  return ((read(0, &c, 1) == 1) ? (unsigned char) c : EOF);
}

int bufGetChar(void) {
  char buf[BUFSIZ];
  char *bp = buf;
  static int n = 0;

  if (n == 0) { // empty buffer
    n = read(0, buf, sizeof buf); // byte #
    bp = buf;
  }

  return (--n >= 0) ? (unsigned char) *bp++ : EOF;
}
