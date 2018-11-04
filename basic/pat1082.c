#include <stdio.h>
#include <stdlib.h>
typedef struct Item { int ID, x, y; } Item;
int compare(const void *left, const void *right) {
  Item *l = (Item *)left;
  Item *r = (Item *)right;
  int x1 = l->x, y1 = l->y, x2 = r->x, y2 = r->y;
  return x1 * x1 + y1 * y1 > x2 * x2 + y2 * y2 ? 1 : -1;
}
int main() {
  int N;
  scanf("%d", &N);
  Item arr[N];
  for (int i = 0; i < N; i++)
    scanf("%d %d %d", &arr[i].ID, &arr[i].x, &arr[i].y);
  qsort(arr, N, sizeof(Item), compare);
  printf("%04d %04d", arr[0].ID, arr[N - 1].ID);
  return 0;
}