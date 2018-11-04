#include <stdio.h>
#include <string.h>
int main() {
  int N, jia[3] = {0}, yi[3] = {0};
  scanf("%d", &N);
  getchar();
  for (int i = 0; i < N; i++) {
    char line[4];
    gets(line);
    if (strcmp(line, "C J") == 0)
      jia[1]++;
    else if (strcmp(line, "J B") == 0)
      jia[2]++;
    else if (strcmp(line, "B C") == 0)
      jia[0]++;
    else if (strcmp(line, "J C") == 0)
      yi[1]++;
    else if (strcmp(line, "B J") == 0)
      yi[2]++;
    else if (strcmp(line, "C B") == 0)
      yi[0]++;
  }
  int jiaWin = jia[0] + jia[1] + jia[2], yiWin = yi[0] + yi[1] + yi[2];
  printf("%d %d %d\n", jiaWin, N - jiaWin - yiWin, yiWin);
  printf("%d %d %d\n", yiWin, N - jiaWin - yiWin, jiaWin);
  printf("%c %c\n",
         jia[0] >= jia[1] ? (jia[0] >= jia[2] ? 'B' : 'J')
                          : (jia[1] >= jia[2] ? 'C' : 'J'),
         jia[0] >= yi[1] ? (yi[0] >= yi[2] ? 'B' : 'J')
                         : (yi[1] >= yi[2] ? 'C' : 'J'));
  return 0;
}