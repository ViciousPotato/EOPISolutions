import Data.Bits

parity1 :: Integer -> Integer
parity1 0 = 0
parity1 x = (x .&. 1) `xor` parity1 (shiftR x 1)

main = do
     print (parity1 8)
     print (parity1 9)