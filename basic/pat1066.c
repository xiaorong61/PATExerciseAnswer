#include <stdio.h>
int main() {
  int N, M, min, max, alter;
  scanf("%d %d %d %d %d", &N, &M, &min, &max, &alter);
  for (int i = 0, input; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &input);
      printf(j == 0 ? "%03d" : " %03d",
             min <= input && input <= max ? alter : input);
    }
    putchar('\n');
  }
  return 0;
}