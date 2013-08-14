class parity {
	static short parity1(int x) {
		short result = 0;

		while (x != 0) {
			result ^= (x & 1);
			x >>= 1;
		}

		return result;
	}

	public static void main(String[] args) {
		System.out.println("parity1(8)=" + parity1(8));
		System.out.println("parity1(9)=" + parity1(9));
	}
}
