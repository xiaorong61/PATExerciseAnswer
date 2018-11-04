#include <stdio.h>
typedef struct Number {
  char symbol;
  long integer, son, mother;
} Number;
int gcd(int n1, int n2) { return n2 == 0 ? n1 : gcd(n2, n1 % n2); }
Number standard(Number n) {
  Number result = n;
  if (result.son < 0) {
    result.symbol = '-';
    result.son *= -1;
  } else
    result.symbol = '+';
  result.integer = result.son / result.mother;
  result.son = result.son % result.mother;
  int _gcd = gcd(result.son, result.mother);
  result.son /= _gcd;
  result.mother /= _gcd;
  return result;
}
void printNumber(Number n) {
  Number tmp = standard(n);
  if (tmp.integer == 0 && tmp.son == 0) {
    putchar('0');
    return;
  }
  if (tmp.symbol == '-') printf("(-");
  if (tmp.integer > 0) printf("%ld", tmp.integer);
  if (tmp.integer > 0 && tmp.son > 0) putchar(' ');
  if (tmp.son > 0) printf("%ld/%ld", tmp.son, tmp.mother);
  if (tmp.symbol == '-') putchar(')');
}
Number add(Number n1, Number n2) {
  Number result;
  result.son = n1.son * n2.mother + n2.son * n1.mother;
  result.mother = n1.mother * n2.mother;
  return result;
}
Number sub(Number n1, Number n2) {
  Number result;
  result.son = n1.son * n2.mother - n2.son * n1.mother;
  result.mother = n1.mother * n2.mother;
  return result;
}
Number mult(Number n1, Number n2) {
  Number result;
  result.son = n1.son * n2.son;
  result.mother = n1.mother * n2.mother;
  return result;
}
Number div(Number n1, Number n2) {
  Number result;
  result.son = n1.son * n2.mother;
  result.mother = n1.mother * n2.son;
  if (result.mother < 0) {
    result.son *= -1;
    result.mother *= -1;
  }
  return result;
}
void printExpression(Number n1, Number n2, char operator) {
  printNumber(n1);
  printf(" %c ", operator);
  printNumber(n2);
  printf(" = ");
  switch (operator) {
    case '+':
      printNumber(add(n1, n2));
      break;
    case '-':
      printNumber(sub(n1, n2));
      break;
    case '*':
      printNumber(mult(n1, n2));
      break;
    case '/':
      if (n2.son == 0)
        printf("Inf");
      else
        printNumber(div(n1, n2));
  }
  putchar('\n');
}

int main() {
  Number n1, n2;
  scanf("%ld/%ld %ld/%ld", &n1.son, &n1.mother, &n2.son, &n2.mother);
  printExpression(n1, n2, '+');
  printExpression(n1, n2, '-');
  printExpression(n1, n2, '*');
  printExpression(n1, n2, '/');
  return 0;
}