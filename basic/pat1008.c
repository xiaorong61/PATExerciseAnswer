#include <stdio.h>
void move(int arr[], int length, int time) {
  time = time % length;
  for (int i = 0; i < time; i++) {
    int tmp = arr[length - 1];
    for (int j = length - 1; j > 0; j--) arr[j] = arr[j - 1];
    arr[0] = tmp;
  }
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  int arr[N];
  for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
  move(arr, N, M);
  for (int i = 0; i < N; i++) printf(i == 0 ? "%d" : " %d", arr[i]);
  return 0;
}