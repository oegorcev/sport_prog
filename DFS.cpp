typedef vector<int64> Edges_t;

struct Node
{
	Node() : color(0) {}
	int64 color;
	Edges_t edges;
};

typedef vector<Node>  Graph_t;

Graph_t graph;

void DFS(int64 i, int64 color)
{
	if (graph[i].color != 0)
	{
		if (graph[i].color != color) EXIT(-1);
		else return;
	}

	graph[i].color = color;


	forn(j, graph[i].edges.size())
	{
		int64 u = graph[i].edges[j];

		DFS(u, 3 - color);
	}
}
