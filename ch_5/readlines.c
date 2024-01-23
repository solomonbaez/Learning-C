#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
int get_lines(char *, int);

int read_lines(char *line_p[], int max_lines) {
  int len, n_lines;
  char *p, line[MAXLEN];

  n_lines = 0;
  while ((len = get_lines(line, MAXLEN)) > 0) {
    if (n_lines > max_lines) {
      return -1;
    } else {
      strcpy(p, line);
      line_p[n_lines++] = p;
    }
  }

  return n_lines;
}

int get_lines(char *p, int max_len) {
  int c;
  int len = 0;
  while ((c = getchar()) != EOF && len++ < max_len - 1) {
    *p++ = c;
  }

  *p = '\0';
  return len;
}

void write_lines(char *line_p, int n_lines) {
  while (n_lines--) {
    printf("%c\n", *line_p++);
  }
}
