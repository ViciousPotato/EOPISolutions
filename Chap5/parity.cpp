#include <iostream>

short parity1(unsigned long x) {
  short result = 0;

  while (x) {
    result ^= (x & 1);
    x >>= 1;
  }

  return result;
}

short parity2(unsigned long x) {
  short result = 0;

  while (x) {
    result ^= 1;
    x &= (x-1);
  }

  return result;
}

int main() {
  std::cout << "parity1 9 = " << parity1(9) << std::endl;
  std::cout << "parity1 8 = " << parity1(8) << std::endl;
  std::cout << "parity2 9 = " << parity2(9) << std::endl;
  std::cout << "parity2 8 = " << parity2(8) << std::endl;
  return 0;
}
