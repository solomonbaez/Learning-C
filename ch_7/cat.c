#include <stdio.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  void filecopy(FILE *, FILE *);

  if (argc == 1) {
    filecopy(stdin, stdout);
  }
  else {
    while (--argc > 0) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        printf("cat: can not open %s\n", *argv);
      }
      else {
        filecopy(fp, stdout);
        fclose(fp);
      }
    }
  }

  return 0;
}

void filecopy(FILE *from, FILE *to) {
  int c;
  while ((c = getc(from)) != EOF) {
    putc(c, to);
  }
}
