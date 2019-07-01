#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >

const int MAX = 1e3 + 5;
string s;
int memo[MAX][MAX], cases = 1;

int fn(int l, int r)
{
	if(l >= r)
		return 0;

	int &ret = memo[l][r];

	if(ret != -1)
		return ret;

	if(s[l] == s[r])
		return ret = fn(l + 1, r - 1);

	int ret1 = fn(l + 1, r) + 1; // add right or remove left
	int ret2 = fn(l, r - 1) + 1; // add left or remove right
	int ret3 = fn(l + 1, r - 1) + 1; // replace
	return ret = min(ret1, min(ret2, ret3));
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);
	int t;
	cin >> t;

	while(t --)
	{
		cin >> s;
		memset(memo, -1, sizeof(memo));
		cout <<  "Case " << cases ++ << ": " << fn(0, s.size() - 1) << "\n";
	}

	return 0;
}
