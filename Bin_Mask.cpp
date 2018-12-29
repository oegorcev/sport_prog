// n - количество элементов

for (int64 i = 1; i < (1 << n); ++i)
{
	Check(i);
}


void Check(int64 i)
{
	while (n)
	{
		if (n & 1)
		{
			//Do something
		}

		n >>= 1;
	}
}