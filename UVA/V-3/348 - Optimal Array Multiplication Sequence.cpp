#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >

const int MAX = 1e1 + 5;
int n;
pi a[MAX];
pair < pi, long long > memo[MAX][MAX];

pair < pi, long long > fn(int l, int r)
{
	if(l == r)
		return {a[l], 0};

	if(r - l == 1)
		return {{a[l].f, a[r].s}, a[l].f * a[l].s * a[r].s};

	pair < pi , long long > &ret = memo[l][r];

	if(ret.s != 0)
		return ret;

	ret.s = 1e9;

	for(int i = l; i < r; i ++)
	{
		const auto & p1 = fn(l, i);
		const auto & p2 = fn(i + 1, r);

		if(p1.s + p2.s + p1.f.f * p2.f.f * p2.f.s < ret.s)
		{
			ret.f = {p1.f.f, p2.f.s};
			ret.s = p1.s + p2.s + p1.f.f * p2.f.f * p2.f.s;
		}
	}

	return ret;
}

void trace(int l, int r)
{
	if(r == l)
	{
		cout << "A" << r + 1 ;
		return;
	}

	if(r - l == 1)
	{
		cout << "(A" << l + 1 << " x A" << r + 1 << ")";
		return ;
	}

	long long idx = -1;
	pair < pi, long long > ret;
	ret.s = 1e9;

	for(int i = l; i < r; i ++)
	{
		const auto & p1 = fn(l, i);
		const auto & p2 = fn(i + 1, r);

		if(p1.s + p2.s + p1.f.f * p2.f.f * p2.f.s < ret.s)
		{
			idx = i;
			ret.f = {p1.f.f, p2.f.s};
			ret.s = p1.s + p2.s + p1.f.f * p2.f.f * p2.f.s;
		}
	}

	cout << "(";
	trace(l, idx);
	cout << " x ";
	trace(idx + 1, r);
	cout << ")";
}

int main()
{
	int cases = 1;

	while(cin >> n && n)
	{
		for(int i = 0; i < n; i ++)
			cin >> a[i].f >> a[i].s;

		for(int i = 0; i < n; i ++)
			for(int j = 0; j < n; j ++)
				memo[i][j] = {{0,0 }, 0};

		cout << "Case " << cases ++ << ": ";
		fn(0, n - 1);
		trace(0, n - 1);
		cout << "\n";
	}
	return 0;
}
