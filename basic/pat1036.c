#include <stdio.h>
int main() {
  int N;
  char C;
  scanf("%d %c", &N, &C);
  for (int i = 1, line = (int)(N / 2.0 + 0.5); i <= line; i++) {
    for (int j = 1; j <= N; j++)
      putchar(i == 1 || i == line || j == 1 || j == N ? C : ' ');
    putchar('\n');
  }
  return 0;
}