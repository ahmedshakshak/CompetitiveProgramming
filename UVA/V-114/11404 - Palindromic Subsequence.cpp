#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >

const int MAX = 1e3 + 5;
pair < int, string > memo[MAX][MAX];
string s;

pair < int, string > comp(const pair < int, string > &a, const pair < int, string > &b)
{
	if(a.f > b.f || (a.f == b.f && a.s < b.s))
		return a;

	return b;
}

pair < int, string > fn(int l, int r)
{
	if(l > r)
		return {0, ""};
	else if(l == r)
		return {1, string(1, s[l])};

	auto &ret = memo[l][r];

	if(ret.f != -1)
		return ret;

	if(s[l] == s[r])
		return ret = {2 + fn(l + 1, r - 1).f, s[l] + fn(l + 1, r - 1).s + s[r]};

	const auto ret1 = fn(l + 1, r);
	const auto ret2 = fn(l, r - 1);

	return ret = comp(ret1, ret2);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);

	while(cin >> s)
	{
		for(int i = 0; i < s.size(); i ++)
			for(int j = 0; j < s.size(); j ++)
				memo[i][j] = {-1, ""};

		cout << fn(0, s.size() - 1).s << "\n";
	}

	return 0;
}
