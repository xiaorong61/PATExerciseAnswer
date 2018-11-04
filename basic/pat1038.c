#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int grade[101] = {0};
  for (int i = 0, N = nextInt(); i < N; i++) grade[nextInt()]++;
  for (int i = 0, K = nextInt(); i < K; i++)
    printf(i == 0 ? "%d" : " %d", grade[nextInt()]);
  return 0;
}