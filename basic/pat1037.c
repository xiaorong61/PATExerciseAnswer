#include <stdio.h>
typedef struct Money {
  char symbol;
  int Galleon, Sickle, Knut;
} Money;
void printMoney(Money money) {
  printf(money.symbol == '-' ? "-%d.%d.%d" : "%d.%d.%d", money.Galleon,
         money.Sickle, money.Knut);
}
Money sub(Money a, Money b) {
  if (a.Galleon < b.Galleon || (a.Galleon < b.Galleon && a.Sickle < b.Sickle) ||
      (a.Galleon < b.Galleon && a.Sickle == b.Sickle && a.Knut < b.Knut)) {
    Money tmp = sub(b, a);
    tmp.symbol = '-';
    return tmp;
  }
  if (a.Knut < b.Knut) {
    a.Knut += 29;
    a.Sickle--;
  }
  if (a.Sickle < b.Sickle) {
    a.Sickle += 17;
    a.Galleon--;
  }
  Money result = {'+', a.Galleon - b.Galleon, a.Sickle - b.Sickle,
                  a.Knut - b.Knut};
  return result;
}
int main() {
  Money should, real;
  scanf("%d.%d.%d", &should.Galleon, &should.Sickle, &should.Knut);
  scanf("%d.%d.%d", &real.Galleon, &real.Sickle, &real.Knut);
  printMoney(sub(real, should));
  return 0;
}