#include <math.h>
#include <stdio.h>
int main() {
  int N;
  scanf("%d", &N);
  double max = 0;
  while (N-- > 0) {
    int real, unreal;
    scanf("%d %d", &real, &unreal);
    double _sqrt = sqrt(real * real + unreal * unreal);
    if (_sqrt > max) max = _sqrt;
  }
  printf("%.2lf", max);
  return 0;
}