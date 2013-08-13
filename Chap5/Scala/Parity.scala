// Actually I don't know how to write a good scala program.
// yet.
object Parity {
  def parity1(x: Int): Int = {
    if (x == 0) return 0
    return (x & 1) ^ parity1(x >> 1)
  }
  
  def main(args: Array[String]) {
    println(parity1(9))
  }
}