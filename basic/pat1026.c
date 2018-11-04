#include <stdio.h>
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  float time = (float)(M - N) / 100;
  int hour = (int)time / 3600;
  int minute = (int)time % 3600 / 60;
  float second = time - hour * 3600 - minute * 60;
  printf("%02d:%02d:%02.0f", hour, minute, second);
  return 0;
}