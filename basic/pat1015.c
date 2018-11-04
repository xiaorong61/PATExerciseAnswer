#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int ID;
  int de;
  int cai;
} Student;
int compare(const void *_left, const void *_right) {
  Student *left = (Student *)_left;
  Student *right = (Student *)_right;
  if (left->de + left->cai > right->de + right->cai) return -1;
  if (left->de + left->cai == right->de + right->cai && left->de > right->de)
    return -1;
  if ((left->de + left->cai == right->de + right->cai &&
       left->de == right->de && left->ID < right->ID))
    return -1;
  return 1;
}
int main() {
  int N, L, H, count[4] = {0};
  scanf("%d %d %d", &N, &L, &H);
  Student result[4][N];
  for (int i = 0; i < N; i++) {
    Student stu;
    scanf("%d %d %d", &(stu.ID), &(stu.de), &(stu.cai));
    if (stu.de < L || stu.cai < L) continue;
    if (stu.de >= H && stu.cai >= H)
      result[0][count[0]++] = stu;
    else if (stu.de >= H && stu.cai < H)
      result[1][count[1]++] = stu;
    else if (stu.de < H && stu.cai < H && stu.de >= stu.cai)
      result[2][count[2]++] = stu;
    else
      result[3][count[3]++] = stu;
  }
  printf("%d\n", count[0] + count[1] + count[2] + count[3]);
  for (int i = 0; i < 4; i++) {
    qsort(result[i], count[i], sizeof result[i][0], compare);
    for (int j = 0; j < count[i]; j++)
      printf("%d %d %d\n", result[i][j].ID, result[i][j].de, result[i][j].cai);
  }
  return 0;
}