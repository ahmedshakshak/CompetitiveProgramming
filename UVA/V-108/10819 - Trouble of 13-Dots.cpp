#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pii pair < int, int >
#define pll pair < long long, long long >
typedef bitset < 16 > MASK;

const int MAX = 100 + 1, MAXE = 5e4 + 1, mod = 1e9 + 7;
int budget, n, dp[MAX][(int)1e4 + 250], path[MAX][(int)1e4 + 250];
pii p[MAX];

int fn(int i, int j)
{
	if(j - budget > 200)
		return -1 * (1 << 30);

	if(i == -1)
	{
		if(j <= budget || (j > 2000 && j - budget <= 200))
			return 0;

		return -1 * (1 << 30);
	}

	if(dp[i][j] != -1)
		return dp[i][j];

	return dp[i][j] = max(fn(i - 1, j), fn(i - 1, j + p[i].f) + p[i].s);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(cin >> budget >> n)
	{
		for(int i = 0; i < n; i ++)
			cin >> p[i].f >> p[i].s;

		memset(dp, -1, sizeof dp);
		cout << max(fn(n - 1, 0), 0) << "\n";
	}

	return 0;
}
