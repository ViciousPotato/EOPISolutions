require('bitops')

parity1 <- function(x) {
  result <- 0
  while (x != 0) {
    result <- bitXor(result, bitAnd(x, 1))
    x <- bitShiftR(x, 1)
  }
  return(result)
}

print(parity1(8))
print(parity1(9))