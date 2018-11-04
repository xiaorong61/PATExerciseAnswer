#include <stdio.h>
void printFormat(int n) {
  if (n < 0) {                 // 如果 n 负数
    putchar('-');              // 打印负号
    printFormat(-n);           // 用函数自身格式化打印正数
  } else if (n < 1000) {       // 如果 n 介于 [0, 1000)
    printf("%d", n);           // 直接打印
  } else {                     // 如果 n >= 1000
    printFormat(n / 1000);     // 使用函数本身输出去掉低三位的 n
    putchar(',');              // 插入逗号
    printf("%03d", n % 1000);  // 打印低三位
  }
}
int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printFormat(a + b);
  return 0;
}