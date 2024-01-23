#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int get_line(char *, int);

int main(int arg_c, char *arg_v[]) {
  char line[MAXLINE];
  long line_n = 0;
  int c, except = 0, number = 0, found = 0;

  while (--arg_c > 0 && (*++arg_v)[0] == '-') {
    while ((c = *++arg_v[0])) {
      switch (c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("illegal option: %c\n", c);
          arg_c = 0;
          found = -1;
          break;
      }
    }
  }

  if (arg_c != 1) {
    printf("grep usage: find -x -n pattern\n");
  } else {
    while (get_line(line, MAXLINE)) {
      line_n++;

      if ((strstr(line, arg_v[1]) != NULL) != except) {
        if (number) {
          printf("%ld\n", line_n);
        }
        printf("%s", line);
        found++;
      }
    }
  }

  return found;
}

int get_line(char *line, int max_lines) {
  int c, i;
  i = 0;
  while ((c = getchar()) != EOF && i < max_lines - 1) {
    line[i++] = c;
  };

  line[i] = '\0';
  return i;
}
