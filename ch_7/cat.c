#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  void filecopy(FILE *, FILE *);
  char *program = argv[0];

  if (argc == 1) {
    filecopy(stdin, stdout);
  }
  else {
    while (--argc > 0) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", program, *argv);
      }
      else {
        filecopy(fp, stdout);
        fclose(fp);
      }
    }
  }

  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", program);
    return 2;
  }

  return 0;
}

void filecopy(FILE *from, FILE *to) {
  int c;
  while ((c = getc(from)) != EOF) {
    putc(c, to);
  }
}
