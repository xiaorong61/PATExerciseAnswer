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
char *tail(char str[]) { return str + 1; }
int sum(char str[]) {
  return strlen(str) == 0 ? 0 : str[0] - '0' + sum(tail(str));
}
int main() {
  char str[101];
  scanf("%s", str);
  printNumByPinyin(sum(str));
  return 0;
}
