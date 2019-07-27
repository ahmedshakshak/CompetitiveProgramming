#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >
#define pl pair < long long, long long >
typedef bitset < 16 > MASK;

int x, y, cases = 1;
map < int, vector < int > > adj;
map < int, bool > visited;

int dfs(int u)
{
	visited[u] = true;
	int c = 1;

	for(const auto v : adj[u])
		if(!visited[v])
			c += dfs(v);

	return c;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("output.txt", "w", stdout);

	while(cin >> x >> y && x >= 0 && y >= 0)
	{
		for(auto &v : adj)
			v.s.clear();

		int m = 0;
		adj.clear();
		visited.clear();

		while(x && y)
		{
			m++;
			adj[x].push_back(y);
			adj[y].push_back(x);
			cin >> x >> y;
		}

		if(m == 0)
			cout << "Case " << cases++ << " is a tree.\n";
		else if(m != adj.size() - 1)
			cout << "Case " << cases++ << " is not a tree.\n";
		else
		{
			int n = dfs((*adj.begin()).f);
			if(n - 1 != m)
				cout << "Case " << cases++ << " is not a tree.\n";
			else
				cout << "Case " << cases++ << " is a tree.\n";
		}
	}

	return 0;
}
