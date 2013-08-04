function parity1(x) {
  var result = 0;

  while (x) {
    result ^= (x & 1);
    x >>= 1;
  }

  return result;
}

console.log(parity1(9))
