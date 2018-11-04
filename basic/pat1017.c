#include <stdio.h>
#include <string.h>
int main() {
  char A[1001];
  int B;
  scanf("%s %d", A, &B);
  int length = strlen(A);
  int remain = 0;
  for (int i = 0; i < length; i++) {
    int current = A[i] - '0';
    int tmp = (10 * remain + current) / B;
    if (tmp != 0 || i > 0 || length == 1) {
      printf("%d", tmp);
    }
    remain = (10 * remain + current) % B;
  }
  printf(" %d", remain);
  return 0;
}