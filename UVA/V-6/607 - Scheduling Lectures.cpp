#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pii pair < int, int >
#define pll pair < long long, long long >
typedef bitset < 16 > MASK;

const int MAX = 1e3 + 1, MAXE = 5e4 + 1, mod = 1e9 + 7;

int a[MAX], n, c, l;
pii dp[MAX][MAX];

int DI(int t)
{
	if(t == 0)
		return 0;
	else if(t > 10)
		return (t - 10) * (t - 10);
	else
		return -1 * c;
}

pii chose(int i, int j)
{
	pii ret1, ret2, ret;

	if(j - a[i] < 0)
		ret1 = {1e6, 1e6};
	else
		ret1 = dp[i + 1][j - a[i]];

	ret2 = dp[i + 1][l - a[i]];
	ret2.s += DI(j);
	ret2.f++;

	if(ret1.f < ret2.f)
		ret = ret1;
	else if(ret2.f < ret1.f)
		ret = ret2;
	else
	{
		if(ret1.s < ret2.s)
			ret = ret1;
		else
			ret = ret2;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cases = 0;

	while(cin >> n && n)
	{
		if(cases)
			cout << "\n";

		cin >> l >> c;
		memset(dp, 0, sizeof dp);

		for(int i = 0; i < n; i ++)
			cin >> a[i];

		for(int i = n; i >= 0; i --)
			for(int j = 0; j <= l; j ++)
			{
				if(i == n)
					dp[i][j] = {0, DI(j)};
				else
				{
					dp[i][j] = chose(i, j);
				}
			}

		auto ans = dp[0][l];
		cout << "Case " << ++cases << ":\n" << "Minimum number of lectures: " << ans.f + 1 << "\nTotal dissatisfaction index: " << ans.s << "\n";
	}

	return 0;
}
