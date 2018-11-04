#include <ctype.h>
#include <stdio.h>
int main() {
  int arr[128] = {0};
  for (char c; (c = getchar()) != '\n';) arr[(int)tolower(c)]++;
  char max = 'a';
  for (int i = 'b'; i < 'z'; i++)
    if (arr[i] > arr[(int)max]) max = i;
  printf("%c %d", max, arr[(int)max]);
  return 0;
}