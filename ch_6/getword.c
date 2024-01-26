#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_word(char *word, int max_word) {
  int c;
  int get_char(void);
  void un_get_char(int);

  char *w = word;
  while (isspace(c = get_char()));
  if (c != EOF) {
    *w++ = c;
  }

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for ( ; --max_word > 0; w++) {
    if (!isalnum(*w = get_char())) {
      un_get_char(*w);
      break;
    }
  }

  *w = '\0';
  return word[0];
}
