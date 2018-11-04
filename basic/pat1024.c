#include <stdio.h>
#include <string.h>
int indexOf(char c, char arr[], int start, int end) {
  return start > end
             ? -1
             : arr[start] == c ? start : indexOf(c, arr, start + 1, end);
}
void rightMove(char arr[], int index, int times) {
  if (times == 0) return;
  arr[index] = arr[index + 1];
  arr[index + 1] = '.';
  rightMove(arr, index + 1, times - 1);
}
int main() {
  char operator1 = getchar();
  char base[10000];
  int length = 0;
  for (char c = getchar(); c != 'E'; c = getchar()) base[length++] = c;
  int n;
  scanf("%d", &n);
  if (operator1 == '-') printf("-");
  if (n < 0) {
    printf("0.");
    for (int i = 0; i < -n - 1; i++) printf("0");
    for (int i = 0; i < length; i++)
      if (base[i] != '.') printf("%c", base[i]);
  } else if (n >= length - 2) {
    for (int i = 0; i < n + 2; i++)
      if (i >= length)
        printf("0");
      else if (base[i] != '.')
        printf("%c", base[i]);
  } else {
    rightMove(base, indexOf('.', base, 0, length - 1), n);
    for (int i = 0; i < length; i++) printf("%c", base[i]);
  }
  return 0;
}