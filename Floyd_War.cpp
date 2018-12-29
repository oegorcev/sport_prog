void FloydWar()
{
	forn(k, n)
	{
		forn(i, n)
		{
			forn(j, n)
			{
				vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
			}
		}
	}
}