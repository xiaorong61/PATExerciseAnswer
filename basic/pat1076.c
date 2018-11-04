#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  char str[4];
  for (int i = 0; i < N * 4; i++) {
    scanf("%s", str);
    if (str[2] == 'T') printf("%d", str[0] - 'A' + 1);
  }
}