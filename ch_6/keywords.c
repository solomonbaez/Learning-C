#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NKEYS (sizeof key_table / sizeof key_table[0])
#define MAXWORD 100

struct key {
  char *word;
  int count;
} key_table[] = {
  { "int", 0 },
  { "float", 0},
  { "double", 0},
  { "long", 0},
  { "short", 0},
  { "char", 0},
  { "const", 0},
  { "extern", 0},
};

int get_word(char *, int);
int bin_search(struct key *, char *, int);

int main(void) {
  int n;
  char word[MAXWORD];

  printf("number of keys: %d\n", (int) NKEYS);

  while (get_word(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      if ((n = bin_search(key_table, word, NKEYS)) >= 0) {

        printf("word: %s\n", word);
        key_table[n].count++;
      }
    }
  }

  for (n = 0; n < NKEYS; n++) {
    printf("%4d, %s\n", key_table[n].count, key_table[n].word);
  }

  return 0;
}

int bin_search(struct key *kt, char *word, int n_keys) {
  int cmp, m;
  int l = 0;
  int r = n_keys - 1;

  while (l <= r) {
    m = (l + r) / 2;

    if ((cmp = strcmp(word, kt[m].word) < 0)) {
      r = m - 1;
    } else if (cmp > 0) {
      l = m + 1;
    } else {
      return m;
    }
  }

  return -1;
}

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
