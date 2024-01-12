#include <stdio.h>

void count_chars() {
  double count;

  printf("Enter some text (press Ctrl+C to end):\n");

  for (count = 0; getchar() != EOF; ++count) {
    printf("%0.f\n", count); /* float and double are both represented by f */
  }
}

void read_lines() {
  int c, lines;

  printf("Enter some text (press Ctrl+C to end):\n");

  lines = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++lines;
    }

    printf("%d\n", lines);
  }
}

void count_non_char() {
  int c, blanks, tabs, lines;

  printf("Enter some text (press Ctrl+C to end):\n");

  blanks = 0;
  tabs = 0;
  lines = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks;
    } else if (c == '\t') {
      ++tabs;
    } else if (c == '\n'){
      ++lines;
    }

    printf("blanks: %d \ntabs: %d\nlines: %d", blanks, tabs, lines);
  }
}

int main() {
  int c;

  printf("Enter some text (press Ctrl+C to end):\n");

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }
}
