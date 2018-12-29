int64 GCD(int64 a, int64 b)
{
	if (b == 0) return a;
	else return GCD(b, a % b);
}