#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >

const int MAX = 1e3 + 5;
string s;
int memo[MAX][MAX];

int fn(int l, int r)
{
	if(l >= r)
		return 0;

	int &ret = memo[l][r];

	if(ret != -1)
		return ret;

	if(s[l] == s[r])
		return ret = fn(l + 1, r - 1);

	int ret1 = fn(l + 1, r) + 1; // insert right
	int ret2 = fn(l, r - 1) + 1; // insert left

	return ret = min(ret1, ret2);
}

void trace(int l, int r)
{
	if(l > r)
		return;

	if(l == r)
	{
		cout << s[r];
		return;
	}
	if(s[l] == s[r])
	{
		cout << s[l];
		trace(l + 1, r - 1);
		cout << s[r];
	}
	else
	{
		int ret1 = fn(l + 1, r) + 1; // insert right
		int ret2 = fn(l, r - 1) + 1; // insert left
		int ret = fn(l ,r);

		if(ret == ret1)
		{
			cout << s[l];
			trace(l + 1, r);
			cout << s[l];
		}
		else
		{
			cout << s[r];
			trace(l, r - 1);
			cout << s[r];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("output.txt", "w", stdout);

	while(cin >> s)
	{
		memset(memo, -1, sizeof(memo));
		cout << fn(0, s.size() - 1) << " ";
		trace(0, s.size() - 1);
		cout << "\n";
	}

	return 0;
}
