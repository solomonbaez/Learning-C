#include <stdio.h>

#define TABSTOP 4
void detab();
void entab();
void fold();

int main() {
  fold();
}

// EX. 1-20
void detab() {
  int c, i;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (i = TABSTOP; i >= 0; --i) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  }
}

// EX. 1-21
void entab() {
  int c;
  int i = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++i;
    } else if (c == '\t') {
      i += TABSTOP;
    } else {
      while (i > 0) {
        if (i >= TABSTOP) {
          i -= TABSTOP;
          putchar('\t');
        } else {
          --i;
          putchar(' ');
        }
      }
      putchar(c);
    }
  }
}

#define COLSTOP 10
// EX. 1-22
void fold() {
  int c, i, j, k;
  int findend = 1;

  // declare line
  int line[COLSTOP];
  // define line
  for (i = COLSTOP; i >= 0; --i) {
    line[i] = ' ';
  }

  i = j = k = 0;
  while ((c = getchar()) != EOF) {
    line[i] = c;

    if (i == COLSTOP - 1) {
      while (findend == 1) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
          k = 0;
          for (j = 0; j < COLSTOP; ++j) {
            if (j <= i) {
              putchar(line[j]);

            } else if (j > i && line[j] != ' ' && line[j] != '\t' && line[i] != '\n') {
              line[k] = line[j];
              ++k;

            }
          }

          i = k;
          findend = 0;

        } else {
          --i;
        }
      }

      findend = 1;
      putchar('\n');
    }

    ++i;
  }
}
