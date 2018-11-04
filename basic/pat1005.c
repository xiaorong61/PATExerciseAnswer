#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int compare(const void *left, const void *right) {
  return *(int *)right - *(int *)left;
}
void Callatz(int num, bool cover[]) {
  if (num == 1) return;
  if (num % 2 == 0) {
    cover[num / 2] = true;
    Callatz(num / 2, cover);
    return;
  }
  cover[(3 * num + 1) / 2] = true;
  Callatz((3 * num + 1) / 2, cover);
}
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int K = nextInt(), input[K], result[K], length = 0;
  for (int i = 0; i < K; i++) input[i] = nextInt();
  for (int i = 0; i < K; i++) {
    bool cover[10000] = {false};
    for (int j = 0; j < K; j++)
      if (i != j) Callatz(input[j], cover);
    if (!cover[input[i]]) result[length++] = input[i];
  }
  qsort(result, length, sizeof result[0], compare);
  for (int i = 0; i < length; i++) printf(i == 0 ? "%d" : " %d", result[i]);
  return 0;
}