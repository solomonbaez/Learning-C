#include <stdio.h>

int bs(int nums[], int target, int r) {
  int l = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    if (target < nums[m]) {
      r = m - 1;
    } else if (target > nums[m]) {
      l = m + 1;
    } else {
      return 1;
    }
  }

  return 0;
}

int main(void) {
  int x[6];
  for (int i = 0; i < 6; ++i) {
    x[i] = i;
  }

  int result = bs(x, 4, 5);
  if (result == 1) {
    printf("true\n");
  } else {
    printf("false\n");
  }
}
