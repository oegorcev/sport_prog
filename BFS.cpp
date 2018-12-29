void BFS(int64 v)
{
	vector<bool> visited(graph.size());
	queue<int64> stack;

	stack.push(v);
	visited[v] = true;
	answer[v] = 0;

	while (!stack.empty())
	{
		int64 curEdge = stack.front();
		stack.pop();

		for (int64 it : graph[curEdge].edges)
		{
			if (visited[it] == false)
			{
				visited[it] = true;
				answer[it] = answer[curEdge] + 1;
				stack.push(it);
			}
		}

	}

}