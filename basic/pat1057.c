#include <ctype.h>
#include <stdio.h>
#include <string.h>
int sum(char str[], int start, int end) {
  return start > end
             ? 0
             : (isalpha(str[start]) ? tolower(str[start]) - 'a' + 1 : 0) +
                   sum(str, start + 1, end);
}
void countNumByBase(int num, int base, int count[]) {
  if (num == 0) return;
  if (num >= base) countNumByBase(num / base, base, count);
  count[num % base]++;
}
int main() {
  char str[100000 + 1];
  gets(str);
  int count[2] = {0, 0};
  countNumByBase(sum(str, 0, strlen(str) - 1), 2, count);
  printf("%d %d", count[0], count[1]);
  return 0;
}