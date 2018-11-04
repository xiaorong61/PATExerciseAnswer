#include <iostream>
#include <set>
using namespace std;
int nextInt() {
  int result;
  cin >> result;
  return result;
}
int sumByDigits(int n) { return n == 0 ? 0 : sumByDigits(n / 10) + n % 10; }
int main() {
  int N = nextInt();
  set<int> s;
  for (int i = 0; i < N; i++) s.insert(sumByDigits(nextInt()));
  printf("%d\n", (int)s.size());
  for (auto it = s.begin(); it != s.end(); it++)
    printf(it == s.begin() ? "%d" : " %d", *it);
  return 0;
}