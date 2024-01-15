#include <stdio.h>

char* escape(char* t, char* s) {
  int j = 0;
  for (int i = 0; t[i] != '\0'; ++i) {
    switch (t[i]) {
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }

  s[j] = '\0'; // null escape
  return s;
}

int main(void) {
  char s[1000];
  char t[] = "hello\tworld";

  char* escaped_s = escape(t, s);
  printf("original: %s, escaped: %s\n", t, escaped_s);

  return 0;
}
