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

short *precomputed_parity;

short parity3(unsigned long x) {
  return precomputed_parity[x >> 48] ^
    precomputed_parity[(x >> 32) & 0xFFFF] ^
    precomputed_parity[(x >> 16) & 0xFFFF] ^
    precomputed_parity[x & 0xFFFF];
}

int main() {
  std::cout << "parity1 9 = " << parity1(9) << std::endl;
  std::cout << "parity1 8 = " << parity1(8) << std::endl;
  std::cout << "parity2 9 = " << parity2(9) << std::endl;
  std::cout << "parity2 8 = " << parity2(8) << std::endl;

  // Calculate precomputed parity array.
  precomputed_parity = (short *)malloc(0xFFFF+1);
  for (int i = 0; i <= 0xFFFF; i++) {
    precomputed_parity[i] = parity1(i);
  }
  std::cout << "parity3 9 = " << parity3(9) << std::endl;
  std::cout << "parity3 8 = " << parity3(8) << std::endl;
  free(precomputed_parity);
  return 0;
}
