#include <iostream>
using namespace std;
int main() {
  string str;
  cin >> str;
  int result = 0, countT = 0;
  for (size_t i = 0; i < str.length(); i++)
    if (str[i] == 'T') countT++;
  for (size_t i = 0, countP = 0; i < str.length(); i++)
    if (str[i] == 'P')
      countP++;
    else if (str[i] == 'A')
      result = (result + countP * countT) % 1000000007;
    else
      countT--;
  cout << result;
  return 0;
}