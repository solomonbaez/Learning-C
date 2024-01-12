#include <stdio.h>

int main() {
  int c;

  printf("Enter some text (press Ctrl+D or Ctrl+Z to end):\n");
  printf("%d", EOF);

  /* getchar() consumes a bit so we can inline it's assignment to c */
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
