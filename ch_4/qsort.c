#include <stdio.h>

void qsort(int nums[], int l, int r) {
  int i, last;
  void swap(int nums[], int i, int j);

  if (l >= r) {
    return; // base case
  }

  swap(nums, l, (l + r) / 2);
  last = l;

  for (i = l + 1; i <= r; i++) {
    if (nums[i] < nums[l]) {
      swap(nums, ++last, i);
    }
  }

  swap(nums, l, last);
  qsort(nums, l, last - 1);
  qsort(nums, last + 1, r);
}

void swap(int nums[], int i, int j) {
  int tmp;

  tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

int main(void) {
  int nums[7] = { 2, 4, 10, 2, 1, 4, 5 };

  printf("original: ");
  for (int i = 0; i < 7; i++) {
    printf("%d", nums[i]);
  }
  printf("%c",'\n');

  qsort(nums, 0, 7);

  printf("sorted: ");
  for (int i = 0; i < 7; i++) {
    printf("%d", nums[i]);
  }
  printf("%c",'\n');
}
