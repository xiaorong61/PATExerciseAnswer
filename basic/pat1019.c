#include <stdio.h>
#include <stdlib.h>
int compare(const void *left, const void *right) {
  return *(int *)right - *(int *)left;
}
int main() {
  int N;
  scanf("%d", &N);
  for (int arr[] = {N / 1000, N % 1000 / 100, N % 100 / 10, N % 10};;) {
    qsort(arr, 4, sizeof(int), compare);
    int num1 = 0, num2 = 0;
    for (int i = 0; i < 4; i++) num1 = num1 * 10 + arr[i];
    for (int i = 3; i >= 0; i--) num2 = num2 * 10 + arr[i];
    int diff = num1 - num2;
    printf("%04d - %04d = %04d\n", num1, num2, diff);
    if (diff == 6174 || diff == 0) break;
    arr[0] = diff / 1000;
    arr[1] = diff % 1000 / 100;
    arr[2] = diff % 100 / 10;
    arr[3] = diff % 10;
  }
  return 0;
}