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

const int MAX = 1000 + 2, mod = 1e9 + 7;
string str1, str2;
vector < string > v1, v2;
int dp[MAX][MAX];

void split(string &s, vector < string > &v)
{
	string str = "";

	for(const auto &ch : s)
	{
		if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
			str += ch;
		else if(str != "")
			v.push_back(str), str = "";
	}

	if(str != "")
		v.push_back(str);
}

void preProcess()
{
	v1.clear();
	v2.clear();
	v1.push_back("");
	v2.push_back("");
	split(str1, v1);
	split(str2, v2);
	memset(dp, 0, sizeof dp);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cases = 0;

	while(getline(cin, str1) && getline(cin , str2))
	{
		cases++;
		cout << std::right << std::setw(2) << cases << ". " ;

		if(str1 == "" || str2 == "")
		{
			cout << "Blank!\n";
			continue;
		}

		preProcess();

		for(int i = 1 ; i < v1.size(); i ++)
			for(int j = 1; j < v2.size(); j ++)
			{
				if(v1[i] == v2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}

		cout << "Length of longest match: " << dp[v1.size() - 1][v2.size() - 1] << "\n";
	}

	return 0;
}
