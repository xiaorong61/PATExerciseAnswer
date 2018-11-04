#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define unless(condition) if (!(condition))
typedef struct People {
  char name[6];
  int year, month, day;
} People;
bool olderThan(People *a, People *b) {
  if (a->year < b->year) return true;
  if (a->year == b->year && a->month < b->month) return true;
  if (a->year == b->year && a->month == b->month && a->day < b->day)
    return true;
  return false;
}
bool equals(People *a, People *b) {
  return a->year == b->year && a->month == b->month && a->day == b->day;
}
bool youngerThan(People *a, People *b) {
  return !olderThan(a, b) && !equals(a, b);
}
int compare(const void *_left, const void *_right) {
  if (youngerThan((People *)_left, (People *)_right)) return 1;
  return -1;
}
int main() {
  int N;
  scanf("%d", &N);
  People arr[N];
  People thePeople200 = {"_", 2014 - 200, 9, 6}, thePeople0 = {"_", 2014, 9, 6};
  int length = 0;
  for (int i = 0; i < N; i++) {
    People people;
    scanf("%s %d/%d/%d", people.name, &people.year, &people.month, &people.day);
    unless(olderThan(&people, &thePeople200) ||
           youngerThan(&people, &thePeople0)) arr[length++] = people;
  }
  if (length == 0)
    printf("%d", length);
  else {
    qsort(arr, length, sizeof arr[0], compare);
    printf("%d %s %s", length, arr[0].name, arr[length - 1].name);
  }
  return 0;
}