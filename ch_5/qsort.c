#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *line_p[MAXLINES];

int read_lines(char *line_p[], int max_lines);
void write_lines(char *line_p[], int n_lines);

void qsort(char *line_p[], int l, int r, int (*cmp) (void *, void *));
int num_cmp(char *, char *);

int main(int arg_c, char *arg_v[]) {
  int n_lines;
  int numeric = 0; // numeric sort

  if (arg_c > 1 && strcmp(arg_v[1], "-n") == 0) {
    numeric = 1;
  }
  if ((n_lines = read_lines(line_p, MAXLINES)) >= 0) {
    qsort(line_p, 0, n_lines - 1, (int (*)(void *, void *))(num_cmp));
    write_lines(line_p, n_lines);

    return 0;
  } else {
    printf("error: too many lines -> max = %d", MAXLINES);
    return 1;
  }
}

void qsort(char *line_p[], int l, int r, int (*cmp) (void *, void *)) {
  int i, last;
  void swap(void *v[], int l, int r);

  if (l >= r) {
    return;
  }

  swap((void **) line_p, l, (l + r) / 2);
  last = l;

  for (i = l + 1; i <= r; i++) {
    if ((*cmp) (line_p[i], line_p[l]) < 0) {
      swap((void **) line_p, ++last, i);
    }
  }

  swap((void **) line_p, l, last);
  // qsort(line_p, l, last - 1, cmp);
  // qsort(line_p, last + 1, r, cmp);

}

void swap(void *v[], int l, int r) {
  void *tmp = v[l];
  v[l] = v[r];
  v[r] = tmp;
}

int num_cmp(char *p_1, char *p_2) {
  double v_1, v_2;

  v_1 = atof(p_1);
  v_2 = atof(p_2);

  if (v_1 < v_2) {
    return -1;
  } else if (v_1 > v_2) {
    return 1;
  } else {
    return 0;
  }
}
