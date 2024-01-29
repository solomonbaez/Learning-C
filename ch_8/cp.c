#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define PERMS 0666 // RW for owner, group, others

void error(char *, ...);

int main(int argc, char *argv[]) {
  int from, to, n;
  char buf[BUFSIZ];

  if (argc != 3) {
    error("usage: cp from to");
  }
  if ((from = open(argv[1], O_RDONLY, 0)) == -1) {
    error("cp: cannot open %s\n", argv[1]);
  }
  if ((to = open(argv[2], PERMS)) == -1) {
    error("cp: cannot create %s, mode %03o", argv[2], PERMS);
  }
  while ((n = read(from, buf, BUFSIZ)) > 0) {
    if (write(to, buf, n) != n) { // note byte number contract
      error("cp: write error on file %s", argv[2]);
    }
  }

  return 0;
}

void error(char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  fprintf(stderr, "error: ");
  fprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
  exit(1);
}
