#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 100

struct node {
  char *word;
  int count;
  struct node *l_node;
  struct node *r_node;
};

struct node *add_node(struct node *, char *);
void print_tree(struct node *);
int get_word(char *, int);

int main(void) {
  char word[MAXWORD];

  struct node *root = NULL;
  while (get_word(word, MAXWORD) != EOF) {
    if (isalnum(word[0])) {
      root = add_node(root, word);
    }
  }
  print_tree(root);

  return 0;
}

struct node *node_alloc(void);
char *save_str(char *);

struct node *add_node(struct node *n, char *s) {
  int cmp;

  if (n == NULL) {
    n = node_alloc();
    n->word = save_str(s);
    n->count = 1;
    n->l_node = n->r_node = NULL;
  } else if ((cmp = strcmp(s, n->word)) == 0) {
    n->count++;
  } else if (cmp < 0) {
    n->l_node = add_node(n->l_node, s);
  } else {
    n->r_node = add_node(n->r_node, s);
  }

  return n;
}

// malloc wrapper
struct node *node_alloc(void) {
  return (struct node *) malloc(sizeof(struct node));
}

char *save_str(char *s) {
  char *p;
  p = (char *) malloc(strlen(s) + 1); // + 1 incl. terminator
  if (p != NULL) {
    strcpy(p, s);
  }

  return p;
}

// this is unoptimized -> worst case behaviour is linear search
void print_tree(struct node *n) {
  if (n != NULL) {
    print_tree(n->l_node);
    printf("%4d %s\n", n->count, n->word);
    print_tree(n->r_node);
  }
}
