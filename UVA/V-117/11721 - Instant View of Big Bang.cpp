#include <bits/stdc++.h>
using namespace std;
#define pi pair < int, int >
#define pli pair < long long, int >
#define pll pair < long long, long long >
#define f first
#define s second
#define MASK bitset < 20 >

struct Edge
{
	int from, to, w;
	Edge(int from, int to, int w) : from(from), to(to), w(w) {};
};
const int MAX = 1e3 + 1, logMAX = log2(MAX) + 1;
int n, m, x, y, t, q, dist[MAX], cases;
bool visited[MAX];
vector < int > adj[MAX];
vector < Edge > edges;
set < int > ans;

void dfs(int u)
{
	visited[u] = true;
	ans.insert(u);

	for(const auto &v : adj[u])
		if(!visited[v])
			dfs(v);
}

void bf(int s)
{
	for(int i = 0; i < n; i ++)
		dist[i] = 1e9;

	for(int i = 0; i < n; i ++)
		for(const auto &edge : edges)
			if(dist[edge.from] > dist[edge.to] + edge.w)
			{
				dist[edge.from] = dist[edge.to] + edge.w;

				if(i == n - 1)
				{
					ans.insert(edge.to);
					ans.insert(edge.from);
				}
			}

}

void init()
{
	for(int i = 0; i < n; i ++)
		visited[i] = false, adj[i].clear();

	ans.clear();
	edges.clear();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> q;

	while(q --)
	{
		cin >> n >> m;
		init();

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> t;
			edges.push_back(Edge(x, y, t));
			adj[y].push_back(x);
		}

		bf(0);

		for(const auto &u : ans)
			if(!visited[u])
				dfs(u);

		cout << "Case " << ++cases << ":";

		if(ans.empty())
			cout << " impossible";

		for(const auto &v : ans)
			cout << " " << v;

		cout << "\n";
	}
	return 0;
}
