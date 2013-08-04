import Data.Bits

parity1 :: Integer -> Integer
parity1 1 = 0
parity1 x = 0 `xor` (x .&. 1) `xor` parity1 (shiftR x 1)

main = do
     print (parity1 9)