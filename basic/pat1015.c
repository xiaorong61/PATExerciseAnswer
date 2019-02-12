#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum index { ID, DE, CAI };
int compare(const void *_l, const void *_r) {
  int *l = (int *)_l;
  int *r = (int *)_r;
  if (l[DE] + l[CAI] > r[DE] + r[CAI]) return -1;
  if (l[DE] + l[CAI] == r[DE] + r[CAI] && l[DE] > r[DE]) return -1;
  if ((l[DE] + l[CAI] == r[DE] + r[CAI] && l[DE] == r[DE] && l[ID] < r[ID]))
    return -1;
  return 1;
}
int main() {
  int N, L, H, count[4] = {0};
  scanf("%d %d %d", &N, &L, &H);
  int result[4][N][CAI + 1];
  for (int i = 0; i < N; i++) {
    int stu[CAI + 1];
    scanf("%d %d %d", &(stu[ID]), &(stu[DE]), &(stu[CAI]));
    if (stu[DE] < L || stu[CAI] < L) continue;
    if (stu[DE] >= H && stu[CAI] >= H)
      memcpy(result[0][count[0]++], stu, sizeof(stu));
    else if (stu[DE] >= H && stu[CAI] < H)
      memcpy(result[1][count[1]++], stu, sizeof(stu));
    else if (stu[DE] < H && stu[CAI] < H && stu[DE] >= stu[CAI])
      memcpy(result[2][count[2]++], stu, sizeof(stu));
    else
      memcpy(result[3][count[3]++], stu, sizeof(stu));
  }
  printf("%d\n", count[0] + count[1] + count[2] + count[3]);
  for (int i = 0; i < 4; i++) {
    qsort(result[i], count[i], sizeof result[0][0], compare);
    for (int j = 0; j < count[i]; j++)
      printf("%d %d %d\n", result[i][j][ID], result[i][j][DE],
             result[i][j][CAI]);
  }
  return 0;
}
