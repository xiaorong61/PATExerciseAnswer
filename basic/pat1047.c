#include <stdio.h>
int main() {
  int N, arrGrade[1001] = {0}, championID, max = 0;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int ID, _, grade;
    scanf("%d-%d %d", &ID, &_, &grade);
    arrGrade[ID] += grade;
    if (arrGrade[ID] > max) {
      championID = ID;
      max = arrGrade[ID];
    }
  }
  printf("%d %d", championID, max);
  return 0;
}