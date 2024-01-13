#include <stdio.h>

void parse_input_digits() {
  int c, i, n_white, n_other;
  int n_digit[10];

  // initialize
  n_white = n_other = 0;
  for (i = 0; i <= 9; ++i) {
    n_digit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') { // normalize
      ++n_digit[c - '0'];
    } else if (c == ' ') {
      ++n_white;
    } else {
      ++n_other;
    }

    printf("digits: ");
    for (i = 0; i <= 9; ++i) {
      printf("%d", n_digit[i]);
    }

    printf("\nwhitespace: %d\n", n_white);
    printf("other: %d\n", n_other);
  }
}
