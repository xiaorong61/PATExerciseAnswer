#include <stdio.h>
int main() {
  int map[128] = {0};
  for (int c; (c = getchar()) != EOF;) map[c]++;
  while (map['P'] > 0 || map['A'] > 0 || map['T'] > 0 || map['e'] > 0 ||
         map['s'] > 0 || map['t'] > 0) {
    if (map['P']-- > 0) putchar('P');
    if (map['A']-- > 0) putchar('A');
    if (map['T']-- > 0) putchar('T');
    if (map['e']-- > 0) putchar('e');
    if (map['s']-- > 0) putchar('s');
    if (map['t']-- > 0) putchar('t');
  }
  return 0;
}