local bit = require 'numberlua'

local function parity1(x)
  local result = 0
  while (x ~= 0) do
     result = bit.bxor(result, bit.band(x, 1))
     x = bit.rshift(x, 1)
  end
  return result
end

print(parity1(8))
