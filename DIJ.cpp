
struct Edge
{
	Edge(int64 vv, int64 lenn) : v(vv), len(lenn) {};
	int64 v;
	int64 len;
};

typedef vector<int64> Edges_t;
typedef vector<Edge> Edges;


struct Node
{
	Node() : color('w'), dist(LLONG_MAX) {}
	char color;
	int64 dist;
	Edges edges;
};

typedef vector<Node> Graph_t;

Graph_t graph;


void Dij(int64 s)
{
	priority_queue<pair<int64, int64>, vector<pair<int64, int64>>, greater<pair<int64, int64>>> que;
	graph[s].dist = 0;

	que.push({ 0, s });

	while (!que.empty())
	{
		int64 u = que.top().second;
		int64 dist = que.top().first;

		que.pop();

		if (graph[u].dist != dist) continue;

		for (int64 i = 0; i < graph[u].edges.size(); ++i)
		{
			int64 v = graph[u].edges[i].v;
			int64 newDist = dist + graph[u].edges[i].len;

			if (newDist < graph[v].dist)
			{
				graph[v].dist = newDist;
				que.push({ newDist, v });
			}
		}
	}
}
