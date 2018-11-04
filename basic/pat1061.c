#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int N = nextInt(), M = nextInt(), fullScore[M], trueAnswer[M];
  for (int i = 0; i < M; i++) fullScore[i] = nextInt();
  for (int i = 0; i < M; i++) trueAnswer[i] = nextInt();
  for (int i = 0; i < N; i++) {
    int total = 0;
    for (int j = 0; j < M; j++) {
      int current = nextInt();
      if (current == trueAnswer[j]) total += fullScore[j];
    }
    printf("%d\n", total);
  }
  return 0;
}