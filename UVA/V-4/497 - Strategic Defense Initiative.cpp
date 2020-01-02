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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str;
	getline(cin, str);
	int t = stoi(str);
	getline(cin, str);

	while(t --)
	{
		getline(cin, str);

		vector < int > v;
		v.push_back(stoi(str));

		while(str != "")
		{
			v.push_back(stoi(str));
			getline(cin, str);
		}

		int n = v.size();
		v.push_back(-1);
		int dp[n + 1][n + 1] = {};
		int path[n + 1][n + 1];

		for(int i = n - 1; i >= 0; i --)
			for(int last = n; last >= 0; last --)
			{
				if(v[i] > v[last] && dp[i + 1][i] + 1 > dp[i + 1][last])
				{
					dp[i][last] = dp[i + 1][i] + 1;
					path[i][last] = i;
				}
				else
				{
					dp[i][last] = dp[i + 1][last];
					path[i][last] = last;
				}
			}

		cout << "Max hits: " << dp[0][n] << "\n";
		int idx = 0, last = n;

		while(idx < n)
		{
			if(idx == path[idx][last])
				cout << v[path[idx][last]] << "\n";

			last = path[idx][last];
			idx++;
		}

		if(t)
			cout << "\n";
	}

	return 0;
}
