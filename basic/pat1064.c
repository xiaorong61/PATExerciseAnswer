#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int compare(const void *left, const void *right) {
  return *(int *)left - *(int *)right;
}
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int sumByDigits(int n) { return n == 0 ? 0 : sumByDigits(n / 10) + n % 10; }
int main() {
  int N = nextInt(), friends[N], length = 0;
  for (int i = 0; i < N; i++) {
    int sum = sumByDigits(nextInt());
    if (bsearch(&sum, friends, length, sizeof(int), compare) == NULL) {
      friends[length++] = sum;
      qsort(friends, length, sizeof(int), compare);
    }
  }
  printf("%d\n", length);
  for (int i = 0; i < length; i++) printf(i == 0 ? "%d" : " %d", friends[i]);
  return 0;
}