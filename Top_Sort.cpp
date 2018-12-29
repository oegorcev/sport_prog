
struct Node
{
	Node() : color('w'), cnt(-1) {}
	char color;
	int64 cnt;
	Edges_t edges;
};

typedef vector<Node> Graph_t;

Graph_t graph;

/*Переменные*/
int64 n;
/*-----------*/

vector<int64> answer;

void DFS(int64 u)
{
	graph[u].color = 'b';

	for (int64 i : graph[u].edges)
	{
		if (graph[i].color == 'w')
		{
			DFS(i);
		}
	}
	answer.push_back(u);
}

void Top_Sort()
{
	for (int64 i = 0; i < graph.size(); ++i)
	{
		if (graph[i].color == 'w')
		{
			DFS(i);
		}
	}
	
	reverse(all(answer));
}

void Read()
{
	int64 n; cin >> n;

	graph.resize(n);

	for(int64 i = 0; i < n; ++i)
	{
		int64 a;
		while (cin >> a)
		{
			if (a == 0) break;
			--a;
			graph[i].edges.push_back(a);
		}
	}

	Top_Sort();

	for (int64 i = 0; i < n; ++i)
	{
		cout << answer[i] + 1 << ' ';
	}
}
