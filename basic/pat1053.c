#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
double nextDouble() {
  double result;
  scanf("%lf", &result);
  return result;
}
int main() {
  int N = nextInt();
  double e = nextDouble();
  int D = nextInt(), maybe = 0, must = 0;
  for (int i = 0; i < N; i++) {
    int K = nextInt(), count = 0;
    for (int j = 0; j < K; j++)
      if (nextDouble() < e) count++;
    if (2 * count > K) K > D ? must++ : maybe++;
  }
  printf("%.1f%% %.1f%%", (double)maybe / N * 100, (double)must / N * 100);
  return 0;
}