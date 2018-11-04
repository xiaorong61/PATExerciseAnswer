#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct People {
  char name[9];
  int height;
} People;
int compare(const void *left, const void *right) {
  if (((People *)left)->height == ((People *)right)->height)
    return -strcmp(((People *)left)->name, ((People *)right)->name);
  return ((People *)left)->height - ((People *)right)->height;
}
void printLine(People arr[], int start, int end) {
  if ((end - start + 1) % 2 == 0) {
    printf("%s ", arr[start].name);
    printLine(arr, start + 1, end);
    return;
  }
  if (start == end) {
    printf("%s", arr[start].name);
    return;
  }
  printf("%s ", arr[start + 1].name);
  printLine(arr, start + 2, end);
  printf(" %s", arr[start].name);
}
void printResult(People arr[], int start, int end, int line) {
  if (line == 0) return;
  int width = (end - start + 1) / line;
  printResult(arr, start + width, end, line - 1);
  printLine(arr, start, start + width - 1);
  putchar('\n');
}
int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  People arr[N];
  for (int i = 0; i < N; i++) scanf("%s %d", arr[i].name, &arr[i].height);
  qsort(arr, N, sizeof(People), compare);
  printResult(arr, 0, N - 1, K);
  return 0;
}