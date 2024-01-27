#include <stdio.h>
#include <string.h>
#define HASHSIZE 101

struct ListNode {
  struct ListNode *next;
  char *name;
  char *def;
};

static struct ListNode *hash_table[HASHSIZE];

unsigned hash(char *s) {
  unsigned hash_val;

  // naive hashing function
  for (hash_val= 0; *s != '\0'; s++) {
    hash_val = *s + 31 * hash_val;
  }

  return hash_val % HASHSIZE;
}

struct ListNode *search(char *s) {
  struct ListNode *np;

  for (np = hash_table[hash(s)]; np != NULL; np = np->next) {
    if (strcmp(s, np->name) == 0) {
      return np;
    }
  }

  return NULL;
}

int main(void) {
  char word[] = "hello";
  struct ListNode node = {NULL, word, ""};
  int i = (int) hash(word);
  hash_table[i] = &node;

  if (search(word) != NULL) {
    printf("Hashing successful for '%s'!\n", word);
  } else {
    printf("Hashing unsuccessful!\n");
  }

  return 0;
}
