#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >
#define pl pair < long long, long long >
typedef bitset < 18 > MASK;

struct Edge
{
	int from, to, w;
	Edge(int from, int to, int w) : from(from), to(to), w(w) {};

	bool operator < (const Edge &e) const
	{
		return w > e.w;
	}
};
const int MAX = 2e4 + 2, logMAX = log2(MAX);
int n, m, s, x, y, w, rank1[MAX], parent1[MAX], parent[MAX][logMAX], cost[MAX][logMAX], level[MAX];
vector < pi > adj[MAX];
bool visited[MAX];
vector < Edge > edges;

class DSU
{
public:
	DSU(int n)
	{
		for(int i = 1; i <= n; i ++)
			rank1[i] = 0, parent1[i] = i;
	}

	int find_parent(int u)
	{
		if(u == parent1[u])
			return u;

		return parent1[u] = find_parent(parent1[u]);
	}

	void link(int u, int v)
	{
		if(rank1[u] < rank1[v])
			swap(v, u);

		parent1[v] = u;

		if(rank1[u] == rank1[v])
			rank1[u]++;
	}

	bool unoin_set(int u, int v)
	{
		int x = find_parent(u), y = find_parent(v);

		if(x != y)
			link(x, y);

		return x!= y;
	}
};

void kruskal()
{
	DSU dsu(n);
	int c = 0;
	sort(edges.begin(), edges.end());

	for(const auto &e : edges)
		if(dsu.unoin_set(e.from, e.to))
		{
			adj[e.from].push_back({e.to, e.w});
			adj[e.to].push_back({e.from, e.w});
			c ++;

			if(c == n - 1)
				break;
		}
}

class LCA
{
private:
	int n;
public:
	LCA(int n)
	{
		for(int j = 0; (1 << j) <= n; j++)
			for(int i = 1; i <= n; i ++)
				parent[i][j] = -1, cost[i][j] = 1e9, visited[i] = false, level[i] = 0;

		this->n = n;
		dfs(1);
		dp();
	}

	void dfs(int u)
	{
		visited[u] = true;
		for(const auto &v : adj[u])
			if(!visited[v.f])
			{
				parent[v.f][0] = u;
				level[v.f] = level[u] + 1;
				cost[v.f][0] = v.s;
				dfs(v.f);
			}
	}

	void dp()
	{
		for(int j = 1; (1 << j) <= n; j ++)
			for(int i = 1; i <= n; i ++)
				if(parent[i][j - 1] != -1)
				{
					parent[i][j] = parent[parent[i][j - 1]][j - 1];
					cost[i][j] = min(cost[parent[i][j - 1]][j - 1], cost[i][j - 1]);
				}
	}

	int lca(int u, int v)
	{
		if(level[u] < level[v])
			swap(u, v);

		int lg, c = 1e9;
		for(lg = 1; (1 << lg) <= level[u]; lg++); lg--;

		for(int i = lg; i >= 0; i --)
		{
			int p = parent[u][i];

			if(p != -1 && level[p] >= level[v])
			{
				c = min(c, cost[u][i]);
				u = p;
			}
		}


		if(u == v)
			return c;

		for(int i = lg; i >= 0; i--)
		{
			int p1 = parent[u][i], p2 = parent[v][i];

			if(p1 != -1 && p1 != p2)
			{
				c = min({c, cost[u][i], cost[v][i]});
				u = p1, v = p2;
			}

		}

		c = min({c, cost[u][0], cost[v][0]});
		return c;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);

	while(cin >> n >> m >> s)
	{
		edges.clear();

		for(int i = 1; i <= n; i ++)
			adj[i].clear();

		while(m --)
		{
			cin >> x >> y >> w;
			edges.push_back(Edge(x, y, w));
		}

		kruskal();
		LCA lca(n);

		while(s--)
		{
			cin >> x >> y;
			cout << lca.lca(x, y) << "\n";
		}
	}

	return 0;
}
