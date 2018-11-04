#include <stdio.h>
#define repeat(time, body) \
  for (int _ = 0; _ < time; _++) body
int main() {
  int N;
  char c;
  scanf("%d %c", &N, &c);
  if (N != 0) {
    int halfHeight = 1;
    N--;
    for (int i = 3; N >= i * 2; i += 2) {
      halfHeight++;
      N -= i * 2;
    }
    for (int i = halfHeight; i >= 1; i--) {
      repeat(halfHeight - i, putchar(' '));
      repeat(2 * i - 1, putchar(c));
      putchar('\n');
    }
    for (int i = 2; i <= halfHeight; i++) {
      repeat(halfHeight - i, putchar(' '));
      repeat(2 * i - 1, putchar(c));
      putchar('\n');
    }
  }
  printf("%d", N);
  return 0;
}