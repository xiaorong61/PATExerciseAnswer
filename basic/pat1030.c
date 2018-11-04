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
  int N = nextInt(), p = nextInt(), arr[N], result = 0;
  for (int i = 0; i < N; i++) arr[i] = nextInt();
  qsort(arr, N, sizeof arr[0], compare);
  for (int i = 0; i < N; i++)
    for (int j = i + result; j < N && arr[j] <= arr[i] * (long)p; j++)
      result = j - i + 1;
  printf("%d", result);
  return 0;
}