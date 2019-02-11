#include <stdio.h>
int Callatz(int num) {
  if (num == 1) return 0;
  return 1 + (num % 2 == 0 ? Callatz(num / 2) : Callatz((3 * num + 1) / 2));
}
int main() {
  int num;
  scanf("%d", &num);
  printf("%d", Callatz(num));
  return 0;
}
