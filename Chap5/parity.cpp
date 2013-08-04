#include <iostream>

short parity1(unsigned long x) {
  short result = 0;

  while (x) {
    result ^= (x & 1);
    x >>= 1;
  }

  return result;
}

int main() {
  std::cout << parity1(9) << std::endl;
  return 0;
}
