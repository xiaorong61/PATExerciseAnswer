#include <stdio.h>
void printNumByBase(int num, int base) {
  if (num < 0) {
    putchar('-');
    return printNumByBase(-num, base);
  }
  if (num >= base) printNumByBase(num / base, base);
  printf("%d", num % base);
}
int main() {
  int A, B, D;
  scanf("%d %d %d", &A, &B, &D);
  printNumByBase(A + B, D);
  return 0;
}