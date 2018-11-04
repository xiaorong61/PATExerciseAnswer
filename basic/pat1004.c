#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  char name[n][11], id[n][11];
  int score[n], maxIndex = 0, minIndex = 0;
  for (int i = 0; i < n; i++) scanf("%s %s %d", name[i], id[i], &score[i]);
  for (int i = 0; i < n; i++) {
    if (score[i] > score[maxIndex]) maxIndex = i;
    if (score[i] < score[minIndex]) minIndex = i;
  }
  printf("%s %s\n", name[maxIndex], id[maxIndex]);
  printf("%s %s", name[minIndex], id[minIndex]);
  return 0;
}