#include <stdio.h>
#include <stdlib.h>
typedef struct MoonCake {
  double amount, price, unit;
} MoonCake;
int compare(const void *left, const void *right) {
  return ((MoonCake *)left)->unit >= ((MoonCake *)right)->unit ? -1 : 1;
}
int main() {
  int N;
  double need, result = 0;
  scanf("%d %lf", &N, &need);
  MoonCake arr[N];
  for (int i = 0; i < N; i++) scanf("%lf", &arr[i].amount);
  for (int i = 0; i < N; i++) scanf("%lf", &arr[i].price);
  for (int i = 0; i < N; i++) arr[i].unit = arr[i].price / arr[i].amount;
  qsort(arr, N, sizeof(MoonCake), compare);
  for (int i = 0; i < N && need > 0; i++)
    if (arr[i].amount <= need) {
      result += arr[i].price;
      need -= arr[i].amount;
    } else {
      result += arr[i].unit * need;
      need = 0;
    }
  printf("%.2lf", result);
  return 0;
}