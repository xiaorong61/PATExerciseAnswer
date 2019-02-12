#include <stdio.h>
#include <stdlib.h>
enum index { ID, X, Y };
int square(int x) { return x * x; }
int square_sum(int x, int y) { return square(x) + square(y); }
int compare(const void *_l, const void *_r) {
  int *l = (int *)_l;
  int *r = (int *)_r;
  return square_sum(l[X], l[Y]) - square_sum(r[X], r[Y]);
}
int main() {
  int N;
  scanf("%d", &N);
  int arr[N][Y + 1];
  for (int i = 0; i < N; i++)
    scanf("%d %d %d", &arr[i][ID], &arr[i][X], &arr[i][Y]);
  qsort(arr, N, sizeof(int[Y + 1]), compare);
  printf("%04d %04d", arr[0][ID], arr[N - 1][ID]);
  return 0;
}
