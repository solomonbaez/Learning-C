#include <stdlib.h>

typedef long Align;

union header { // block header
  struct {
    union header *ptr; // next block
    unsigned size; // block size
  } s;
  Align x;
};

typedef union header Header;

static Header base; // empty list
static Header *free_p = NULL;

void *c_malloc(unsigned n_bytes) {
  Header *p, *prev_p;
  Header *more(unsigned);

  unsigned n_units = (n_bytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prev_p = free_p) == NULL) { // no free list
    base.s.ptr = free_p = prev_p = &base;
    base.s.size = 0;
  }

  for (p = prev_p->s.ptr; ; prev_p = p, p = p->s.ptr) {
    if (p->s.size >= n_units) { // check size restriction
      if (p->s.size == n_units) {
        prev_p->s.ptr = p->s.ptr;
      }
      else { // allocate tail
        p->s.size -= n_units;
        p += p->s.size;
        p->s.size = n_units;
      }
      free_p = prev_p;
      return (void *)(p + 1);
    }
    if (p == free_p) { // wrap
      if ((p = more(n_units)) == NULL) { // ask for more space
        return NULL;
      }
    }
  }
}

#define NALLOC 1024

Header *more(unsigned nu) {
  char *cp, *s_brk(int);
  Header *up;

  if (nu < NALLOC) {
    nu = NALLOC;
  }
  cp = s_brk(nu * sizeof(Header));
  if (cp == (char *) -1) { // no space
    return NULL;
  }

  up = (Header *) cp;
  up->s.size = nu;
  free((void *)(up + 1));
  return free_p;
}

void c_fre(void *ap) {
  Header *bp, *p;

  bp = (Header *) ap - 1; // point to block header
  for (p = free_p; !(bp > p && bp < p->s.ptr); p = p->s.ptr) { // walk the linked list
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr)) {
      break; // freed block at arena start / end
    }
  }

  if (bp + bp->s.size == p->s.ptr) { // joint to upper nbr
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  }
  else {
    bp->s.ptr = p->s.ptr;
  }

  if (p + p->s.size == bp) { // join to lower nbr
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  }
  else {
    p->s.ptr = bp;
  }

  free_p = p;
}
