int64 l = 0, r = MAX64;

while (l != r)
{
	int64 mid = l + (r - l) / 2;

	if (Check(mid))
	{
		r = mid;
	}
	else
	{
		l = mid + 1;
	}
}



while (r != l)
{
	int64 mid = l + ((r - l) / 2);

	if (Can(mid))
	{
		l = mid + 1;
	}
	else
	{
		r = mid;
	}
}

cout << r - 1;