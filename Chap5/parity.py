def parity1(x):
  result = 0
  while x:
    result ^= (x & 1)
    x >>= 1

  return result

print parity1(9)
