#include <math.h>
#include <stdbool.h>
#include <stdio.h>
bool isPrime(int num) {
  if (num == 1) return false;
  int root = (int)sqrt(num);
  for (int i = 2; i <= root; i++) {
    if (num % i == 0) return false;
  }
  return true;
}
int main() {
  int M, N;
  scanf("%d %d\n", &M, &N);
  for (int num = 2, i = 0; i < N; num++) {
    if (isPrime(num)) {
      i++;
      if (M <= i) {
        printf("%d", num);
        if ((i - M + 1) % 10 == 0) {
          printf("\n");
        } else {
          if (i != N) printf(" ");
        }
      }
    }
  }
  return 0;
}