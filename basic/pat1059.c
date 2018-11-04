#include <math.h>
#include <stdbool.h>
#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
bool isPrime(int num) {
  if (num == 1) return false;
  int root = sqrt(num);
  for (int i = 2; i <= root; i++)
    if (num % i == 0) return false;
  return true;
}
int indexOf(int c, int arr[], int start, int end) {
  return start > end
             ? -1
             : arr[start] == c ? start : indexOf(c, arr, start + 1, end);
}
int checked[10000];
int main() {
  int N = nextInt(), rank[N];
  for (int i = 0; i < N; i++) rank[i] = nextInt();
  int K = nextInt(), toQuery[K];
  for (int i = 0; i < K; i++) toQuery[i] = nextInt();
  for (int i = 0; i < K; i++) {
    printf("%04d: ", toQuery[i]);
    int currentRank = indexOf(toQuery[i], rank, 0, N - 1) + 1;
    if (currentRank == 0)
      printf("Are you kidding?");
    else if (checked[toQuery[i]])
      printf("Checked");
    else if (currentRank == 1)
      printf("Mystery Award");
    else if (isPrime(currentRank))
      printf("Minion");
    else
      printf("Chocolate");
    printf("\n");
    checked[toQuery[i]] = true;
  }
  return 0;
}