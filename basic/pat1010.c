#include <stdbool.h>
#include <stdio.h>
int main() {
  int left, right;
  bool start = true;
  while (scanf("%d %d", &left, &right) == 2)
    if (left * right == 0) {
      if (start) printf("0 0");
      break;
    } else {
      if (start)
        start = false;
      else
        printf(" ");
      printf("%d %d", left * right, right - 1);
    }
  return 0;
}