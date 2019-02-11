#include <stdio.h>
#include <string.h>

typedef char *String;
String pinyinMap[] = {"ling", "yi",  "er", "san", "si",
                      "wu",   "liu", "qi", "ba",  "jiu"};

void printNumByPinyin(int num) {
  if (num >= 10) {
    printNumByPinyin(num / 10);
    putchar(' ');
  }
  printf("%s", pinyinMap[num % 10]);
}

int _sum(String str, int start, int end) {
  if (start > end) return 0;
  return str[start] - '0' + _sum(str, start + 1, end);
}

int sum(String str) { return _sum(str, 0, strlen(str) - 1); }

int main() {
  char str[101];
  scanf("%s", str);
  printNumByPinyin(sum(str));
  return 0;
}
