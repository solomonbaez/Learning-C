#include <stdio.h>

struct NestedStructure{
  char *name;
  int flags;
  union {
    int i_val;
    float f_val;
    char *s_val;
  } u;
} symtab[10];

int main(void) {
  struct NestedStructure ns;
  ns.name = "structure";
  ns.flags = 0;
  ns.u.f_val = (float) 1.0;

  printf("%f\n", ns.u.f_val);
  return 0;
}
