#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template < typename T >
using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >; // less_equal for keeping duplicates
#define all(x) x.begin(), x.end()
#define pii pair < int, int >
#define pll pair < long long, long long >
#define f first
#define s second
#define MASK bitset < 16 >
const int MAX = 60 + 2;

long long dp[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;

	while(t --)
	{
		string str;
		cin >> str;
		memset(dp, 0, sizeof dp);

		for(int len = 1; len <= str.size(); len ++)
		{
			for(int i = 0, j; i + len <= str.size(); i ++)
			{
				j = i + len - 1;

				if(len == 1)
					dp[i][j] = 1;
				else
				{
					if(str[i] == str[j])
						dp[i][j] = 1 + dp[i + 1][j - 1];

					dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
				}
			}
		}

		cout << dp[0][str.size() - 1] << "\n";
	}

	return 0;
}
