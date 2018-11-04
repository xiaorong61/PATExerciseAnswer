#include <stdio.h>
int main() {
  int mapProvide[128] = {0}, lack = 0, lenProvide = 0, lenNeed = 0;
  for (int c; (c = getchar()) != '\n';) {
    lenProvide++;
    mapProvide[c]++;
  }
  for (int c; (c = getchar()) != '\n';) {
    lenNeed++;
    if (mapProvide[c] > 0)
      mapProvide[c]--;
    else
      lack++;
  }
  printf(lack > 0 ? "No %d" : "Yes %d", lack > 0 ? lack : lenProvide - lenNeed);
  return 0;
}