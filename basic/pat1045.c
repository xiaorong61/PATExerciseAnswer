#include <stdio.h>
#include <stdlib.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int compare(const void *left, const void *right) {
  return *(int *)left - *(int *)right;
}
int main() {
  int N = nextInt(), input[N], sorted[N], result[N], length = 0;
  for (int i = 0; i < N; i++) sorted[i] = input[i] = nextInt();
  qsort(sorted, N, sizeof sorted[0], compare);
  for (int i = 0, max = 1; i < N; i++) {
    if (input[i] > max) max = input[i];
    if (sorted[i] == max && sorted[i] == input[i]) result[length++] = input[i];
  }
  printf("%d\n", length);
  for (int i = 0; i < length; i++) printf(i == 0 ? "%d" : " %d", result[i]);
  putchar('\n');
  return 0;
}