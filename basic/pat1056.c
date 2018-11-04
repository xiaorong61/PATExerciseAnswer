#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  int arr[N];
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  int result = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (i != j) result += arr[i] * 10 + arr[j];
  printf("%d", result);
  return 0;
}