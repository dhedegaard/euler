#include <iostream>
#include <cmath>

using namespace std;

const long double MAX = 1929394959697989990.0;
const long double MIN = 1020304050607080900.0;

static inline bool check_number(long num) {
  int digit;
  int i = 0;
  do {
    digit = num % 10;
    if ((i == 0 && digit != 0) ||
        (i == 2 && digit != 9) ||
        (i == 4 && digit != 8) ||
        (i == 6 && digit != 7) ||
        (i == 8 && digit != 6) ||
        (i == 10 && digit != 5) ||
        (i == 12 && digit != 4) ||
        (i == 14 && digit != 3) ||
        (i == 16 && digit != 2) ||
        (i == 18 && digit != 1)) {
      return false;
    }
    num /= 10;
    i++;
  } while (num > 0);
  return true;
}

int main(int argc, char* argv[]) {
  cout << fixed;

  long realmax = (long) ceill(sqrtl(MAX));
  long realmin = (long) floorl(sqrtl(MIN));

  cout << "realmin: " << realmin << endl;
  cout << "realmax: " << realmax << endl;

  for (long i = realmin; i <= realmax;i++) {
    long isqrt = i * i;
    if (check_number(isqrt))
      cout << i << ": " << isqrt << endl;
  }

  return 0;
}
