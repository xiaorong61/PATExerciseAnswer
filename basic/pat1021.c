#include <stdio.h>
#include <string.h>
int main() {
  char N[1001];
  gets(N);
  int result[10] = {0};
  for (int i = 0, length = strlen(N); i < length; i++) result[N[i] - '0']++;
  for (int i = 0; i < 10; i++)
    if (result[i] > 0) printf("%d:%d\n", i, result[i]);
  return 0;
}