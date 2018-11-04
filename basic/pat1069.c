#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool hasString(char arr[][21], char str[], int start, int end) {
  if (start > end) return false;
  if (strcmp(arr[start], str) == 0) return true;
  return hasString(arr, str, start + 1, end);
}
int main() {
  int M, N, S;
  scanf("%d %d %d", &M, &N, &S);
  char input[M][21];
  for (int i = 0; i < M; i++) scanf("%s", input[i]);
  char result[M][21];
  int length = 0;
  for (int i = S - 1; i < M; i += N) {
    while (hasString(result, input[i], 0, length - 1)) i++;
    strcpy(result[length++], input[i]);
  }
  for (int i = 0; i < length; i++) puts(result[i]);
  if (length == 0) puts("Keep going...");
  return 0;
}