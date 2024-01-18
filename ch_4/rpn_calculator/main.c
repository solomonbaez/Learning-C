#include <stdio.h>
#include <stdlib.h> // atof()
#include "calculator.h"

#define MAX_OP 100

int main(void) {
  int op;
  double non_comm;
  char s[MAX_OP];

  while ((op = get_op(s)) != EOF) {
    switch (op) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '-':
        non_comm = pop();
        push(pop() - non_comm);
        break;
      case '*':
        push(pop() * pop());
        break;
      case '/':
        non_comm = pop();
        if (non_comm != 0.0) {
          push(pop() / non_comm);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  return 0;
}
