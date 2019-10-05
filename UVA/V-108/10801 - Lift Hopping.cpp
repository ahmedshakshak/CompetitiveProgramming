#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template < typename T >
using ordered_set = tree < T, null_type, less_equal < T >, rb_tree_tag, tree_order_statistics_node_update >; // less_equal for keeping duplicates
#define all(x) x.begin(), x.end()
#define pii pair < int, int >
#define pll pair < long long, long long >
#define f first
#define s second

const int MAX = 100 + 1;
int n, k,eleTime[7], x;
string str;
vector < int > eleNodes[7], nodesEle[MAX];

int dijkstra()
{
	int dist[7][MAX] = {}, ans = 1e9;
	bool visited[7][MAX] = {};

	for(int i = 1; i <= 6; i ++)
		for(int j = 1; j < MAX; j ++)
			dist[i][j] = 1e9;

	priority_queue < pair < int, pii >, vector < pair < int, pii > >, greater < pair < int, pii > > > q;

	for(const auto &el : nodesEle[0])
		q.push({0, {0, el}});

	while(!q.empty())
	{
		const auto p = q.top(); q.pop();
		int floor = p.s.f, e = p.s.s;

		if(visited[e][floor])
			continue;

		visited[e][floor] = true;

		for(const auto &el : nodesEle[floor])
		{
			if(el == e)
			{
				for(const auto &f : eleNodes[el])
					if(dist[el][f] > dist[e][floor] + (abs(floor - f) * eleTime[el]))
					{
						dist[el][f] = dist[e][floor] + (abs(floor - f) * eleTime[el]);
						q.push({dist[el][f], {f, el}});
					}
			}
			else
			{
				if(dist[el][floor] > dist[e][floor] + 60)
				{
					dist[el][floor] = dist[e][floor] + 60;
					q.push({dist[el][floor], {floor, el}});
				}
			}
		}

	}

	for(int i = 1; i <= n; i ++)
		ans = min(ans, dist[i][k]);

	return ans == 1e9 ? -1 : ans;
}

int main()
{
	while(cin >> n >> k)
	{
		for(int i = 1; i <= n; i ++)
			cin >> eleTime[i];

		for(int i = 0; i < MAX; i ++)
			nodesEle[i].clear();

		cin.ignore();

		for(int i = 1; i <= n; i ++)
		{
			eleNodes[i].clear();
			getline(cin, str);
			stringstream ss(str);

			while(ss >> x)
				eleNodes[i].push_back(x), nodesEle[x].push_back(i);
		}

		int ans = dijkstra();

		if(ans == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
	}

	return 0;
}
