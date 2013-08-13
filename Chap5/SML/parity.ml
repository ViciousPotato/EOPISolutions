fun parity1 0 = 0
  | parity1 x = IntInf.xorb(IntInf.andb(x, 1), parity1(IntInf.~>>(x, 1))
