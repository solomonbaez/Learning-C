#include <stdio.h>

int bs(int nums[], int target, int r) {
  int l = 0;
  int m = (l + r) / 2;
  while (l <= r && target != nums[m]) {
    m = (l + r) / 2;
    if (target < nums[m]) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  if (target == nums[m]) {
    return 1;
  } else {
    return 0;
  }
}

int main(void) {
  int x[6];
  for (int i = 0; i < 6; ++i) {
    x[i] = i;
  }

  int result = bs(x, 10, 5);
  if (result == 1) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  return 0;
}
