#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NKEYS (sizeof key_table / sizeof key_table[0])
#define MAXWORD 200

struct key {
  char *word;
  int count;
} key_table[] = {
  { "char", 0},
  { "double", 0},
  { "float", 0},
  { "int", 0 },
  { "long", 0},
  { "short", 0},
};

int get_word(char *, int);
struct key *bin_search(struct key *, char *, int);

int main(void) {
  char word[MAXWORD];
  struct key *key_p;

  while (get_word(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      if ((key_p = bin_search(key_table, word, NKEYS)) != NULL) {
        key_p->count++;
      }
    }
  }

  for (key_p = key_table; key_p < key_table + NKEYS; key_p++) {
    printf("%4d, %s\n", key_p->count, key_p->word);
  }

  return 0;
}

struct key *bin_search(struct key *kt, char *word, int n_keys) {
  int cmp;
  struct key *l = &kt[0];
  struct key *r = &kt[n_keys];

  struct key *m;
  while (l < r) {
    // pointer addition is illegal, subtraction is legal
    // note that (r - l) produces an int
    m = l + (r - l) / 2;

    if ((cmp = strcmp(word, m->word)) < 0) {
      r = m;
    } else if (cmp > 0) {
      l = m + 1;
    } else {
      return m;
    }
  }

  return NULL;
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
