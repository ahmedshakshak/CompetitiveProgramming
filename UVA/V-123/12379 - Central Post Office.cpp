#include <bits/stdc++.h>
using namespace std;
#define pi pair < int, int >
#define pli pair < long long, int >
#define pll pair < long long, long long >
#define f first
#define s second
#define MASK bitset < 20 >

const int MAX = 1e4 + 1, logMAX = log2(MAX) + 1;
int n, m, t, x, ans;
vector < int > adj[MAX];

void init()
{
	ans = 0;

	for(int i = 1; i <= n; i ++)
		adj[i].clear();
}

pi dfs(int u, int p)
{
	pi ret = {u, 0};

	for(const auto &v : adj[u])
		if(v != p)
		{
			const auto p = dfs(v, u);

			if(p.s + 1 > ret.s)
				ret = {p.f, p.s + 1};
		}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;

	while(t --)
	{
		init();
		cin >> n;
		ans = 2 * (n - 1);

		for(int i = 1; i <= n; i ++)
		{
			cin >> m;

			while(m --)
			{
				cin >> x;
				adj[i].push_back(x);
			}
		}

		int p = dfs(1, 0).f;
		ans -= dfs(p, 0).s;
		cout << ans << "\n";
	}

	return 0;
}
