int64 BinPow(int64 n, int64 p)
{
	if (p == 0) return 1LL;

	if (p % 2 == 1) return n * (BinPow(n, p - 1);
	else
	{
		int64 k = BinPow(n, p / 2);
		return k  *  k;
	}
}