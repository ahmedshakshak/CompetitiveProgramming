#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define mb(a, b) make_pair(a, b)
#define pi pair < int, int >

const int MAX = 5e3 + 5;
vector < int > adj[MAX], best;
set < int > worest;
int n, m, u, s, e, parent[MAX], mx1;

void init()
{
	for(auto & v : adj)
		v.clear();

	worest.clear();
	best.clear();
}

// getting best root
void Parent(int p, int c)
{
	if(p == -1)
		return;
	// if length of diameter is odd then we have 2 root
	if(mx1 % 2)
	{
		if(c == mx1 / 2 || c == mx1 / 2 + 1)
			best.push_back(p);
	}
	else // if even then we have one root
	{
		if(c == mx1 / 2)
			best.push_back(p);
	}

	Parent(parent[p], c + 1);
}

void dijkstra(int s, bool path)
{
	int dist[n + 1] = {}, mx = 0;

	for(int i = 1; i <= n; i ++)
		dist[i] = parent[i] = -1;

	dist[s] = 0;
	queue < int > q;
	q.push(s);

	while(!q.empty())
	{
		int u = q.front(); q.pop();

		for(const auto & v : adj[u])
		{
			if(dist[v] > dist[u] + 1 || dist[v] == -1)
			{
				dist[v] = dist[u]  + 1;
				mx = max(dist[v], mx);
				q.push(v);

				if(path)
					parent[v] = u;
			}
		}
	}

	for(int i = 1; i <= n; i ++)
		if(dist[i] == mx)
			worest.insert(i);

	if(path)
		for(int i = 1; i <= n; i ++)
			if(dist[i] == mx)
			{
				e = i;
				mx1 = mx;
				return;
			}
}

int main()
{
 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w" ,stdout);
 	while(cin >> n)
 	{
 		for(int i = 1; i <= n; i ++)
 	 	{
 	 		cin >> m;
 	 		while(m--)
 	 		{
 	 			cin >> u;
 	 			adj[i].push_back(u);
 	 		}
 	 	}

 	 	dijkstra(1, false); // getting worst roots in the diameter in an end
 	 	dijkstra(*worest.begin(), true); // getting worst roots in the diameter in an end and getting best root
 	 	Parent(e, 0);
 	 	sort(best.begin(), best.end());
 	 	cout << "Best Roots  :";

 	 	for(const auto & v : best)
 	 		cout << " " <<  v;

 	 	cout << "\nWorst Roots :";

 	 	for(const auto & v : worest)
 	 		cout << " "  << v;

 	 	cout << "\n";
 	 	init();
 	}
 	return 0;
}
