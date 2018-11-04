#include <stdbool.h>
#include <stdio.h>
int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char *M = "10X98765432";
int sum(char arr[], int start, int end) {
  return start > end
             ? 0
             : (arr[start] - '0') * weight[start] + sum(arr, start + 1, end);
}
bool isValid(char str[]) { return M[sum(str, 0, 16) % 11] == str[17]; }
int main() {
  int N, count = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char ID[19];
    scanf("%s", ID);
    if (isValid(ID))
      count++;
    else
      puts(ID);
  }
  if (count == N) puts("All passed");
  return 0;
}