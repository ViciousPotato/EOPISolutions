## sizeof(long)

sizeof(long) == 8 bytes at OS X 64bit machine.

sizeof(long) == 4 bytes at Windows 7 64bit machine.

How to enable windows 64 bit compilation?

## Lua bit operations

http://lua-users.org/wiki/BitwiseOperators

Lua before version 5.2 does not have bitwise operators, which is quite surprising.

## Problems
### Parity

We can see from the code that that constructs we look for in different languages are:

1. function definition syntax
2. looping mechanism
3. binary operations on integers

Once we have all these constructs, we could construct our program.

### Swap bits

Notice the operator precedence:

    if (((x >> l) & 1) != ((x >> j) & 1)) {

vs.

    if ((x >> l) & 1 != (x >> j) & 1) {
    
Also long literals should end with `L`, `1L << 63` is very different
with `1 << 63`.

Use `bitset<N>` to show binary representations of numbers in C++.
