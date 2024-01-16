#include <stdio.h>
#include <string.h>
#include <ctype.h>

// sliding window
char* expand(char* s_1, char s_2[]) {
  char start, finish;
  start = finish = ' ';
  if (s_1[0] != '-') {
    start = s_1[0];
  }

  int end = strlen(s_1) - 1;
  if (s_1[end] != '-') {
    finish = s_1[end];
  }

  int is_digit = (start != ' ') ? isdigit(start) : isdigit(finish);
  int i, c;
  for (
       i = 0, c = (start != ' ') ? start : ((is_digit) ? '0' : 'a');
       c <= ((finish != ' ') ? finish : ((is_digit) ? '9' : 'z'));
       ++i, ++c
  ) {
    s_2[i] = c;
  }

  s_2[i] = '\0';

  return s_2;
}

int main(void) {
  char s[] = "c-z";
  char s_2[28]; // 26 + buf
  char* expanded_s_chars = expand(s, s_2);
  printf("original: %s, expanded: %s\n", s, expanded_s_chars);

  char s_3[] = "2-9";
  char s_4[10]; // 26 + buf
  char* expanded_s_digits = expand(s_3, s_4);
  printf("original: %s, expanded: %s\n", s_3, expanded_s_digits);

  char s_5[] = "-9";
  char s_6[10]; // 26 + buf
  char* expanded_s_digits_nostart = expand(s_5, s_6);
  printf("original: %s, expanded: %s\n", s_5, expanded_s_digits_nostart);

  char s_7[] = "b-";
  char s_8[10]; // 26 + buf
  char* expanded_s_chars_nofinish= expand(s_7, s_8);
  printf("original: %s, expanded: %s\n", s_7, expanded_s_chars_nofinish);

  return 0;
}
