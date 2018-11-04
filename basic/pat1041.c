#include <stdio.h>
int nextInt() {
  int result;
  scanf("%d", &result);
  return result;
}
int main() {
  int N = nextInt();
  long long arr[N][2];
  while (N-- > 0) {
    long long ID, test, final;
    scanf("%lld %lld %lld", &ID, &test, &final);
    arr[test][0] = ID;
    arr[test][1] = final;
  }
  for (int M = nextInt(); M > 0; M--) {
    int test = nextInt();
    printf("%lld %lld\n", arr[test][0], arr[test][1]);
  }
  return 0;
}