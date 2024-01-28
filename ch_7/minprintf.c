#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) {
  va_list arg_p; // iterator of spread arguments
  char *p, *s_val;
  int i_val;
  double d_val;

  va_start(arg_p, fmt); // va interface requires start / end
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch (*++p) {
      case 'd': // int
        i_val = va_arg(arg_p, int);
        printf("%d", i_val);
        break;
      case 'f': // float
        d_val = va_arg(arg_p, double);
        printf("%f", d_val);
        break;
      case 's': // string
        for (s_val = va_arg(arg_p, char *); *s_val; s_val++) {
          putchar(*s_val);
        }
        break;
    }
  }

  va_end(arg_p);
}

int main(void) {
  minprintf("some int: %d, some float: %f, some string: %s\n", 1, 1.0, "hello");
  return 0;
}
