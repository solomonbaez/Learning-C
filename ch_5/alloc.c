#include <stdio.h>

#define ALLOCSIZE 1000

static char alloc_buf[ALLOCSIZE];
static char *alloc_cp = alloc_buf; // first position in alloc

// ask for system memory if available (mocked by alloc_buf)
char *alloc(int n) {
  // check for space
  if (alloc_buf + ALLOCSIZE - alloc_cp >= n) {
    alloc_cp += n; // increment alloc
    return alloc_cp - n;
  } else {
    return 0;
  }
}

// allocate free memory if applicable (p in alloc_buf)
void alloc_free(char *p) {
  if (p >= alloc_buf && p < alloc_buf + ALLOCSIZE) {
    alloc_cp = p;
  }
}

int main(void) {
  // Allocate memory for a string
  char *s = alloc(13); // "hello, world" is 13 characters including the null terminator

  if (s != 0) {
    // Copy the string "hello, world" into the allocated memory
    char *src = "hello, world";
    while ((*s++ = *src++) != '\0');

    // Print the allocated string
    printf("Allocated string: %s\n", s - 13);
    printf("Allocated pointer: %s\n", alloc_cp - 13);

    // Free the allocated memory
    alloc_free(s - 13);
    printf("Freed pointer: %s\n", alloc_cp);
  } else {
    printf("Memory allocation failed\n");
  }

  return 0;
}
