#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int N = nextInt(), M = nextInt(), result[N];
  for (int i = 0; i < N; i++) {
    int G2, sumStudents = 0, numStudents = 0, min = M, max = 0;
    for (int j = 0; j < N; j++) {
      int current = nextInt();
      if (j == 0)
        G2 = current;
      else if (0 <= current && current <= M) {
        if (current < min)
          min = current;
        else if (current > max)
          max = current;
        sumStudents += current;
        numStudents++;
      }
    }
    int G1 = (sumStudents - min - max) / (numStudents - 2);
    result[i] = (int)((G1 + G2) / 2.0 + 0.5);
  }
  for (int i = 0; i < N; i++) printf("%d\n", result[i]);
  return 0;
}