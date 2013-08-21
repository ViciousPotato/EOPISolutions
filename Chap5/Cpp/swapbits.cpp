#include <iostream>
#include <cassert>
#include <bitset>

long swap_bits(long x, int l, int j) {
  if (((x >> l) & 1) != ((x >> j) & 1)) {
    x ^= (1L << l) | (1L << j);
  }
  return x;
}

int main() {
  assert(swap_bits(0L, 0, 63) == 0);
  assert(swap_bits(1L, 0, 63) == 0x8000000000000000);
  assert(swap_bits(8L, 1, 3) == 2);
}
