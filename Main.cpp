#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <map>
#include <iomanip>
#include <functional>
#include <list>
#include <random>
#include <deque>
#include <queue>
#include <regex>
#include <bitset>
#include <cstdio>
#include <numeric>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef long double double64;
typedef vector<int64> Edges_t;

template <typename T> void alert(const T& t) { cout << t; exit(0); }
template<typename T> inline void alert(vector<T> &t, char delim = ' ') { for (T const& ti : t) cout << ti << delim; exit(0); }

#define forn(i, n) for (int64 i = 0; i < int64(n); i++)
#define nfor(i, n) for (int64 i = int64(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int64 i = int64(l); i < int64(r); i++)
#define efor(i, l, r) for (int64 i = int64(l) - 1; i >= int64(r); i--)
#define all(a) (a).begin(), (a).end()
#define mp(x, y) make_pair((x), (y))
#define sqr(a) ((a) * (a)) 
#define y1 asdasdasdasdasdasd
#define min3(a, b, c) min(min(a,b), c)
#define max3(a, b, c) max(max(a,b), c)

const int64 MAX64 = 1 + 1e+18;
const int  MAX = 1 + 1e+9;
const double PI = 3.1415926536;
const int64 CEL = 26;
const string NO = "NO";
const string YES = "YES";

template <typename T>
istream& operator >> (istream& is, vector<T>& in)
{
	forn(i, in.size()) is >> in[i];
	return is;
}

template <typename T>
ostream& operator << (ostream& os, vector<T>& in)
{
	forn(i, in.size())
	{
		os << in[i] << ' ';
	}
	cout << endl;
	return os;
}

struct Point
{
	Point() {};
	Point(double xx, double yy) : x(xx), y(yy) {};

	double x;
	double y;
};

bool operator < (const Point& p1, const Point& p2)
{
	if (p1.x != p2.x) return p1.x < p2.x;
	else return p1.y < p2.y;
}

struct Node
{
	Node() : color(0) {}
	int64 color;
	Point prev;
	Edges_t edges;
};

typedef vector<Node> Graph_t;
typedef vector<vector<Node>> Graph_tt;

Graph_t graph;
Graph_tt g;

void Clear()
{
	forn(i, graph.size())
	{
		graph[i].color = 'w';
	}
}

void DFS(int64 u, int64 newColor)
{
	graph[u].color = newColor;

	for (int64 v : graph[u].edges)
	{
		DFS(v, newColor);
	}
}

// степень двойки if ((i & (i - 1)) == 0)
// ceil(); - вверх floor(n + 0.5); - вниз

/*Переменные*/



/*-----------*/
void Read()
{

}

void Solve()
{

}

void Print()
{	

}

#define TASKNAME "TASKNAME"

int main()
{
#ifdef _DEBUG
	freopen("ReadMe.txt", "r", stdin);
#else
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(0);
		if (TASKNAME != "TASKNAME")
		{
			freopen(TASKNAME".in", "r", stdin);
			freopen(TASKNAME".out", "w", stdout);
		}
		else if (TASKNAME == "1")
		{
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}
#endif

	Read();
	Solve();
	Print();

	return 0;
}