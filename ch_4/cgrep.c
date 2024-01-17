#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[]);
int pattern_match(char* s, char* pattern);
char pattern[] = "ould";

int main(void) {
  char line[MAXLINE];

  while (get_line(line) > 0) {
    if (pattern_match(line, pattern) == 1) {
      printf("%s\n", line);
    }
  }
  return 0;
}

int get_line(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    s[i]= c;
  }

  if (c == '\n') { s[i++] = c; }
  s[i] = '\0';

  return i;
}

int pattern_match(char* s, char* pattern) {
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; s[j] == pattern[k]; j++, k++);
    if (k > 0 && pattern[k] == '\0') {
      return 1;
    }
  }

  return 0;
}
