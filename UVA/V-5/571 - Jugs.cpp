#include <bits/stdc++.h>
using namespace std;
#define pi pair < int, int >
#define pli pair < long long, int >
#define pll pair < long long, long long >
#define f first
#define s second
#define MASK bitset < 20 >

const int MAX = 2e2 + 1, logMAX = log2(MAX) + 1;
enum operation{fillA, fillB, emptyA, emptyB, pourA, pourB, nothing};
unordered_map < int, unordered_map < int, pair < operation, pi > > > parent;
int a, b, c;

void ans(operation op)
{
	if(op == fillB)
		cout << "fill B\n";
	else if(op == emptyB)
		cout << "empty B\n";
	else if(op == fillA)
		cout << "fill A\n";
	else if(op == emptyA)
		cout << "empty A\n";
	else if(op == pourA)
			cout << "pour A B\n";
	else if(op == pourB)
		cout << "pour B A\n";
}

void print(pair < operation, pi > a)
{
	if(a.s.f == 0 && a.s.s == 0)
		return;

	print(parent[a.s.f][a.s.s]);
	ans(a.f);
}

void solve()
{
	queue < pair < operation, pi >>  q;
	unordered_map < int, unordered_map < int, int > > visited;
	q.push({nothing, {0, 0}});
	pair < operation, pi > p;

	while(!q.empty())
	{
		p = q.front(); q.pop();
		visited[p.s.f][p.s.s] = true;

		if(p.s.f == c || p.s.s == c)
			break;

		if(p.s.f != a && !visited[a][p.s.s])
		{
			q.push({fillA, {a, p.s.s}});
			parent[a][p.s.s] = {p.f, {p.s.f, p.s.s}};
		}

		if(p.s.s != b && !visited[p.s.f][b])
		{
			q.push({fillB, {p.s.f, b}});
			parent[p.s.f][b] = {p.f, {p.s.f, p.s.s}};
		}

		if(p.s.f != 0 && !visited[0][p.s.s])
		{
			q.push({emptyA, {0, p.s.s}});
			parent[0][p.s.s] = {p.f, {p.s.f, p.s.s}};
		}

		if(p.s.s != 0 && !visited[p.s.f][0])
		{
			q.push({emptyB, {p.s.f, 0}});
			parent[p.s.f][0] = {p.f, {p.s.f, p.s.s}};
		}

		if(p.s.f != a && p.s.s != 0 && !visited[min(p.s.f + p.s.s, a)][max(p.s.s - (a - p.s.f), 0)])
		{
			q.push({pourB, {min(p.s.f + p.s.s, a), max(p.s.s - (a - p.s.f), 0)}});
			parent[min(p.s.f + p.s.s, a)][max(p.s.s - (a - p.s.f), 0)] = {p.f, {p.s.f, p.s.s}};
		}

		if(p.s.f != 0 && p.s.s != b && !visited[max(p.s.f - (b - p.s.s), 0)][min(p.s.f + p.s.s, b)])
		{
			q.push({pourA, {max(p.s.f - (b - p.s.s), 0), min(p.s.f + p.s.s, b)}});
			parent[max(p.s.f - (b - p.s.s), 0)][min(p.s.f + p.s.s, b)] = {p.f, {p.s.f, p.s.s}};
		}
	}

	print(p);
	cout << "success\n";

	for(auto &p : parent)
		p.second.clear();

	parent.clear();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);

	while(cin >> a >> b >> c)
		solve();

	return 0;
}
