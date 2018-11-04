#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define swap(a, b)         \
  {                        \
    __typeof__(a) tmp = a; \
    a = b;                 \
    b = tmp;               \
  }
void reverse(char str[], int start, int end) {
  if (start >= end) return;
  swap(str[start], str[end]);
  reverse(str, start + 1, end - 1);
}
bool isPalindromic(char str[]) {
  char tmp[1000 + 1];
  strcpy(tmp, str);
  reverse(tmp, 0, strlen(tmp) - 1);
  return strcmp(str, tmp) == 0;
}
void add(char str1[], char str2[], char result[]) {
  int carry = 0, i = 0;
  for (; i < strlen(str1); i++) {
    int current = str1[i] - '0' + str2[i] - '0' + carry;
    if (current >= 10) {
      carry = 1;
      result[i] = current - 10 + '0';
    } else {
      result[i] = current + '0';
      carry = 0;
    }
  }
  if (carry == 1) result[i++] = '1';
  result[i] = '\0';
  reverse(result, 0, i - 1);
}
int main() {
  char str[1000 + 1];
  scanf("%s", str);
  if (isPalindromic(str)) {
    printf("%s is a palindromic number.", str);
    return 0;
  }
  for (int i = 1;; i++) {
    char rev[1001], sum[1001];
    strcpy(rev, str);
    reverse(rev, 0, strlen(rev) - 1);
    add(str, rev, sum);
    printf("%s + %s = %s\n", str, rev, sum);
    if (isPalindromic(sum)) {
      printf("%s is a palindromic number.", sum);
      break;
    } else if (i == 10) {
      puts("Not found in 10 iterations.");
      break;
    }
    strcpy(str, sum);
  }
  return 0;
}