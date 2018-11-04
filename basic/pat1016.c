#include <stdio.h>
#include <string.h>
int main() {
  char A[10], B[10];
  int Da, Db, resultA = 0, resultB = 0;
  scanf("%s %d %s %d", A, &Da, B, &Db);
  for (int i = 0, lengthA = strlen(A); i < lengthA; i++)
    if (A[i] - '0' == Da) resultA = resultA * 10 + Da;
  for (int i = 0, lengthB = strlen(B); i < lengthB; i++)
    if (B[i] - '0' == Db) resultB = resultB * 10 + Db;
  printf("%d", resultA + resultB);
  return 0;
}