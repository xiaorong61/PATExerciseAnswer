#include <stdio.h>
int main() {
  char input[80][20];
  int length = 0;
  while (scanf("%s", input[length]) != EOF) length++;
  for (int i = length - 1; i >= 0; i--) printf(i == 0 ? "%s" : "%s ", input[i]);
  return 0;
}