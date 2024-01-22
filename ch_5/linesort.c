#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *line_p[MAXLINES];

int read_lines(char *line_p[], int max_lines);
void write_lines(char *line_p[], int n_lines);
void qsort(char *line_p[], int l, int r);

int main(void) {
  return 0;
}

#define MAXLEN 1000
int get_line(char *, int);
char *alloc(int);

int read_lines(char *line_p[], int max_lines) {
  int len, n_lines;
  char *p, line[MAXLEN];

  n_lines = 0;
  while ((len = get_line(line, MAXLEN))) {
    if (n_lines >= max_lines || (p = alloc(len)) == NULL)  {
      return -1;
    } else {
      line[len-1] = '\0';
      strcpy(p, line);
      line_p[n_lines++] = p;
    }
  }

  return n_lines;
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

// write array of pointers
void write_lines(char *line_p[], int n_lines) {
  while (n_lines-- > 0) {
    printf("%s\n", *line_p++);
  }
}

void qsort(char *line[], int l, int r) {
  int i, last;
  void swap(char *line[], int l, int r);

  if (l >= r) {
    return;
  }

  int m = (l + r) / 2;
  swap(line, l, m);

  last = l;
  for (i = l + 1; i <= r; i++) {
    if (strcmp(line[i], line[l]) < 0) {
      swap(line, ++last, i);
    }
  }

  swap(line, l, last);
  qsort(line, l, last - 1);
  qsort(line, last + 1, r);
}

void swap(char *line[], int l, int r) {
  char *tmp = line[l];

  line[l] = line[r];
  line[r] = tmp;
}
