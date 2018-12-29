vector<vector<int64>> gg;

int64 Get_Answer(vector<int64> parent)
{
	int64 ret = 0;

	for (int64 i = 1; i < n; ++i)
	{
		ret += gg[i][parent[i]];
	}

	return ret;
}

void Prim_Alg()
{
	vector<int64> used(n, false), parent(n), key(n, LLONG_MAX);

	key[0] = 0;
	parent[0] = -1;

	for (int64 i = 0; i < n - 1; ++i)
	{
		int64 min = LLONG_MAX, u = -1;

		for (int v = 0; v < n; v++)
		{
			if (used[v] == false && key[v] < min)
			{
				min = key[v], u = v;
			}
		}

		used[u] = true;

		for (int64 v = 0; v < n; ++v)
		{
			if (used[v] == false && gg[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = gg[u][v];
			}
		}
	}

	alert(Get_Answer(parent));
}


void Solve()
{
	cin >> n >> m;

	gg.assign(n, vector<int64>(n));

	vector<int64> vertex(m);

	for (int64 i = 0; i < m; ++i)
	{
		cin >> vertex[i];
		vertex[i]--;
	}

	for (int64 i = 0; i < n; ++i)
	{
		for (int64 j = 0; j < n; ++j)
		{
			cin >> gg[i][j];
			if (i == j) gg[i][j] = LLONG_MAX;
		}
	}

	for (int64 i = 0; i < m; ++i)
	{
		for (int64 j = 0; j < m; ++j)
		{
			if (i != j)
			{
				gg[vertex[i]][vertex[j]] = 0;
			}
		}
	}

	Prim_Alg();
}