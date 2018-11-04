#include <stdio.h>
int main() {
  int N, result[2] = {0};
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int jiaHan, jiaHua, yiHan, yiHua;
    scanf("%d %d %d %d", &jiaHan, &jiaHua, &yiHan, &yiHua);
    if (jiaHua == jiaHan + yiHan)
      result[1] += (int)(yiHua != jiaHan + yiHan);
    else
      result[0] += (int)(yiHua == jiaHan + yiHan);
  }
  printf("%d %d", result[0], result[1]);
  return 0;
}