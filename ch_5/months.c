#include <stdio.h>

static char day_table[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day) {
  int leap = (year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0;

  for (int i = 1; i < month; i++) {
    day += day_table[leap][i];
  }

  return day;
}

void month_day(int year, int year_day, int *month_p, int *day_p) {
  int leap = (year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0;

  int i;
  for (i = 1; year_day > day_table[leap][i]; i++) {
    year_day -= day_table[leap][i];
  }

  *month_p = i;
  *day_p = year_day;
}

char *month_name(int n) {
  static char *name[] = {
    "invalid month", "january", "february",
    "march", "april", "may",
    "june", "july", "august",
    "september", "october",
    "november", "december",
  };

  return (n < 0 || n > 12) ? name[0] : name[n];
}

int main(void) {
  char *name = month_name(10);
  printf("%s\n", name);

  return 0;
}
