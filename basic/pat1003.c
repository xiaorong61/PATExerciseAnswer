#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool judge(char string[]) {
  int left = 0, middle = 0, right = 0, i = 0;
  for (; string[i] == 'A'; i++) left++;
  if (string[i] == 'P') {
    for (i++; string[i] == 'A'; i++) middle++;
    if (middle == 0) return false;
    if (string[i] == 'T') {
      for (i++; string[i] == 'A'; i++) right++;
      if (right == left * middle && i == strlen(string)) return true;
    }
  }
  return false;
}
int main() {
  int n;
  scanf("%d", &n);
  char stringList[n][101];
  for (int i = 0; i < n; i++) {
    scanf("%s", stringList[i]);
  }
  for (int i = 0; i < n; i++) {
    printf("%s\n", judge(stringList[i]) ? "YES" : "NO");
  }
  return 0;
}
