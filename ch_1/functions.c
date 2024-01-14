#include <stdio.h>

// strictly define maxlen -> prevent overflow
#define MAXLEN 1000
int get_ln(char line[], int max_line);
void copy_ln(char to[], char from[]);

int main() {
  int len, max;
  char line[MAXLEN], longest[MAXLEN];

  max = 0;
  while ((len = get_ln(line, MAXLEN)) > 0) {
    if (len > max) {
      max = len;
      copy_ln(longest, line);
    }
  }

  if (max > 0) {
    printf("longest line: %s\n", longest);
  }

  return 0;
}


int get_ln(char line[], int max_line) {
  int c, i;

  for (i = 0; i < max_line - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}

void copy_ln(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

// // function prototype
// int power(int m, int n);
// // alternatively: int power(int, int)
// int power(int base, int n) {
//   int result;
//   for (result = 1; n > 0; --n) {
//     result *= base;
//   }
//
//   return result;
// }
