#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
void printArray(int arr[], int start, int end) {
  if (start > end) return;
  printf(" %04d", arr[start]);
  printArray(arr, start + 1, end);
}
int sum(int arr[], int start, int end) {
  return start > end ? 0 : arr[start] + sum(arr, start + 1, end);
}
int main() {
  int N = nextInt(), M = nextInt(), result[N][10], length[N];
  bool black[10000] = {false};
  int count = 0;
  memset(length, 0, sizeof(int[N]));
  for (int i = 0; i < M; i++) black[nextInt()] = true;
  for (int i = 0; i < N; i++) {
    char name[5];
    scanf("%s", name);
    for (int j = 0, K = nextInt(); j < K; j++) {
      int thing = nextInt();
      if (black[thing]) result[i][length[i]++] = thing;
    }
    if (length[i] > 0) {
      count++;
      printf("%s:", name);
      printArray(result[i], 0, length[i] - 1);
      putchar('\n');
    }
  }
  printf("%d %d", count, sum(length, 0, N - 1));
  return 0;
}