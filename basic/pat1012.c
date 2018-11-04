#include <stdbool.h>
#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int N = nextInt();
  int A1 = 0, A1n = 0;
  int A2 = 0, A2n = 0;
  bool Operator = true;
  int A3 = 0;
  int A4Sum = 0, A4n = 0;
  int A5 = 0, A5n = 0;
  for (int i = 0, num; i < N; i++) {
    num = nextInt();
    switch (num % 5) {
      case 0:
        if (num % 2 == 0) {
          A1 += num;
          A1n++;
        }

        break;
      case 1:
        A2 += Operator ? num : -num;
        Operator = !Operator;
        A2n++;
        break;
      case 2:
        A3++;
        break;
      case 3:
        A4Sum += num;
        A4n++;
        break;
      case 4:
        if (num > A5) {
          A5 = num;
          A5n++;
        }
        break;
    }
  }
  // A1
  if (A1n == 0)
    printf("N");
  else
    printf("%d", A1);
  printf(" ");
  // A2
  if (A2n == 0)
    printf("N");
  else
    printf("%d", A2);
  printf(" ");
  // A3
  if (A3 == 0)
    printf("N");
  else
    printf("%d", A3);
  printf(" ");
  // A4
  if (A4n == 0)
    printf("N");
  else
    printf("%.1f", (float)A4Sum / A4n);
  printf(" ");
  // A5
  if (A5n == 0)
    printf("N");
  else
    printf("%d", A5);
  return 0;
}