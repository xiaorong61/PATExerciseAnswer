#include <math.h>
#include <stdbool.h>
#include <stdio.h>
bool isPrime(int num) {
  if (num == 1) return false;
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  int prime[n];
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (isPrime(i)) {
      prime[j] = i;
      j++;
    }
  }
  int result = 0;
  for (int i = 1; i < j; i++) {
    if (prime[i] - prime[i - 1] == 2) {
      result++;
    }
  }
  printf("%d", result);
  return 0;
}