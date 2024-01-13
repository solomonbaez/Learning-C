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

// EX. 1-8
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

// EX. 1-10
void show_non_chars() {
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

#define TRUE 1
#define FALSE 0
void parse_input_structure() {
  int c;
  int nc, nw, nl;
  int is_word;

  printf("Enter some text (press Ctrl+c to end)\n");

  nc = nw = nl = 0;
  is_word = FALSE;

  while ((c = getchar()) != EOF) {
    ++nc;

    if (c == '\n') {
      ++nl;
    }

    if (c == ' ' || c == '\t' || c == '\n') {
      is_word = FALSE;
    } else if (is_word == FALSE) {
      is_word = TRUE;
      ++nw;
    }

    printf("chars: %d\nwords: %d\nlines: %d\n", nc, nw, nl);
  }
}

// EX. 1-12
int main() {
  int c;
  int is_word;

  printf("Enter some text (press Ctrl+c to end)\n");

  is_word = FALSE;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      is_word = FALSE;
    } else if (is_word == FALSE) {
      printf("\n");
      is_word = TRUE;
    }

    putchar(c);
  }

}
