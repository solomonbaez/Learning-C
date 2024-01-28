struct BitField {
  unsigned int is_keyword : 1; // : 1 == field width in bits
  unsigned int is_extern  : 1;
  unsigned int is_static  : 1;
} flags;

int main(void) {
  return 0;
}
