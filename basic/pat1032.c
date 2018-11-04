#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int sum[(int)1e5] = {0}, winnerID = 1;
  for (int i = 0, N = nextInt(); i < N; i++) {
    int schoolID = nextInt();
    sum[schoolID] += nextInt();
    if (sum[schoolID] > sum[winnerID]) winnerID = schoolID;
  }
  printf("%d %d", winnerID, sum[winnerID]);
  return 0;
}