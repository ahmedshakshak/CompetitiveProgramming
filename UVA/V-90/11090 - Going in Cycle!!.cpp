#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >
#define pl pair < long long, long long >
typedef bitset < 16 > MASK;

const int MAX = 50 + 5;
int t, n, m, x, y, w, cases = 1;
vector < pi > adj[MAX];
double ans, dist[MAX][MAX];


void init()
{
	ans = 1e18;

	for(int i = 1; i <= n; i ++)
		adj[i].clear();
}

int check(int u, int v)
{
	for(int i = 0; i < adj[u].size(); i ++)
		if(adj[u][i].f == v)
			return i;

	return -1;
}

double dijkstra(int s)
{
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j++)
			dist[i][j] = 1e18;

	priority_queue < pair < int, pair < double, int > > , vector < pair < int, pair < double, int > > >, greater < pair < int, pair < double, int > > > > q;
	dist[s][0] = 0;
	q.push({0, {0, s}});

	while(!q.empty())
	{
		const auto p = q.top(); q.pop();
		int u = p.s.s, n = p.f;

		for(const auto &v : adj[u])
			if(dist[v.f][n + 1] > dist[u][n] + v.s)
			{
				dist[v.f][n + 1] = dist[u][n] + v.s;
				q.push({n + 1, {dist[v.f][n + 1], v.f}});
			}
	}

	double ret = 1e18;

	for(int i = 1; i <= n; i ++)
		if(dist[s][i] != 1e18)
			ret = min(ret, dist[s][i] / i);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);
	cin >> t;

	while(t --)
	{
		cin >> n >> m;
		init();

		while(m--)
		{
			cin >> x >> y >> w;
			int idx = check(x, y);

			if(idx == -1)
				adj[x].push_back({y, w});
			else if(adj[x][idx].s > w)
			{
				adj[x].erase(adj[x].begin() + idx);
				adj[x].push_back({y, w});
			}

		}

		for(int i = 1; i <= n; i ++)
			ans = min(ans, dijkstra(i));

		if(ans == 1e18)
			cout << "Case #" << cases++ << ": No cycle found.\n";
		else
			cout << "Case #" << cases++ << ": " << fixed << setprecision(2) << ans << "\n";
	}

	return 0;
}
