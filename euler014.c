#include <stdio.h>

int countcollatzchain(long num) {
  int count = 1;
  while (num != 1) {
    if (num % 2 == 0)
      num /= 2;
    else
      num = 3 * num + 1;
    count++;
  }
  return count;
}

int main() {
  int max = 0;
  int maxi = 0;
  int i;
  int newcount;
  for (i = 1;i < 1000000;i++) {
    newcount = countcollatzchain(i);
    if (newcount > max) {
      printf("newmax: %d - oldmax: %d - i: %d\n", newcount, max, i);
      max = newcount;
      maxi = i;
    }
  }
  printf("%d\n", maxi);
  return 0;
}
