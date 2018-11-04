#include <stdio.h>
int main() {
  int arr[10];
  for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);
  for (int i = 1;; i++)
    if (arr[i] != 0) {
      printf("%d", i);
      arr[i]--;
      break;
    }
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < arr[i]; j++) printf("%d", i);
  return 0;
}