#include <stdio.h>
#include <stdlib.h>
int compare(const void *left, const void *right) {
  return *(int *)left - *(int *)right;
}
int main() {
  int N;
  scanf("%d", &N);
  int arr[N];
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  qsort(arr, N, sizeof(int), compare);
  int result = arr[0];
  for (int i = 1; i < N; i++) result = (result + arr[i]) / 2;
  printf("%d", result);
  return 0;
}