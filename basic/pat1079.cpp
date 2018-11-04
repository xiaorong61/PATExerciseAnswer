#include <algorithm>
#include <iostream>
using namespace std;
bool isPalindromic(string str) {
  string rev = str;
  reverse(str.begin(), str.end());
  return str == rev;
}
string add(string str1, string str2) {
  string result = "";
  int carry = 0, i = 0;
  for (int len = str1.length(); i < len; i++) {
    int current = str1[i] - '0' + str2[i] - '0' + carry;
    if (current >= 10) {
      carry = 1;
      result = (char)(current - 10 + '0') + result;
    } else {
      result = (char)(current + '0') + result;
      carry = 0;
    }
  }
  if (carry == 1) result = '1' + result;
  return result;
}
int main() {
  string str;
  cin >> str;
  if (isPalindromic(str)) {
    cout << str << " is a palindromic number.";
    return 0;
  }
  for (int i = 1;; i++) {
    string rev = str;
    reverse(rev.begin(), rev.end());
    string sum = add(str, rev);
    cout << str << " + " << rev << " = " << sum << '\n';
    if (isPalindromic(sum)) {
      cout << sum << " is a palindromic number.";
      break;
    } else if (i == 10) {
      cout << "Not found in 10 iterations.";
      break;
    }
    str = sum;
  }
  return 0;
}