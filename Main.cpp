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
#include <chrono>       // std::chrono::system_clock
#include <unordered_map>
#include <unordered_set>

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
const double PI = acos(-1);;
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

/*
степень двойки if ((i & (i - 1)) == 0)
ceil(); - вверх floor(n + 0.5); - вниз
*/

int64 MID(int64 l, int64 r) { return (l + r) / 2; }
int64 LSON(int64 u) { return u * 2; }
int64 RSON(int64 u) { return u * 2 + 1; }

struct SegmentTree
{
	SegmentTree(int64 size) : sum(size * 4) {}

	void Set(int64 u, int64 sl, int64 sr, int64 position, int64 value)
	{
		if (sl == sr)
		{
			sum[u] = value;
			return;
		}

		int64 mid = MID(sl, sr);
		if (position <= mid) Set(LSON(u), sl, mid, position, value);
		else
		{
			Set(RSON(u), mid + 1, sr, position, value);
		}

		sum[u] = sum[LSON(u)] + sum[RSON(u)];
	}

	int64 GetSum(int64 u, int64 sl, int64 sr, int64 l, int64 r)
	{
		if (sl == l && sr == r)
		{
			return sum[u];
		}

		int64 mid = MID(sl, sr);

		if (r <= mid)
		{
			return GetSum(LSON(u), sl, mid, l, r);
		}
		else if (l > mid)
		{
			return GetSum(RSON(u), mid + 1, sr, l, r);
		}
		else
		{
			return GetSum(LSON(u), sl, mid, l, mid) + GetSum(RSON(u), mid + 1, sr, mid + 1, r);
		}
	}

	vector<int64> sum;
};


bool isPrime(int64 digit)
{
	if (digit == 1) return false;


	for (int64 i = 2; i <= sqrt(digit); ++i)
	{
		if (digit % i == 0) return false;
	}

	return true;
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
	Node() : color('w'), cnt(-1) {}
	char color;
	int64 cnt;
	Edges_t edges;
};

typedef vector<Node> Graph_t;
typedef vector<vector<Node>> Graph_tt;

Graph_t graph;
Graph_tt g;
int64 answerG = 0;

void Clear()
{
	forn(i, graph.size())
	{
		if (graph[i].color == 'g') graph[i].color = 'w';
	}
}

bool Can(int64 i, int64 j)
{
	return false;
	//	return i >= 0 && i < n  && j >= 0 && j < m;
}


int64 GCD(int64 a, int64 b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

/*Переменные*/
int64 n, m, k, w;
string s1, s2;
int64 t1, t2;
/*-----------*/

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
}


void Read()
{
	int64 n; scanf("%lld", &n);

	vector<int64> vec(n);

	for (int64 i = 0; i < n; ++i)
	{
		scanf("%lld", &vec[i]);
	}

	vector<int64> num(1e6 + 1);

	for (int64 i = 0; i < n; ++i)
	{
		for (int64 j = 2; j <= sqrt(vec[i]); ++j)
		{
			if (vec[i] % j)
			{
				num[j]++;
			}
		}
	}

	for (int64 i = 1e6; i >= 0; ++i)
	{
		if (num[i] >= 2) alert(i);
	}
	
	alert(1);
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