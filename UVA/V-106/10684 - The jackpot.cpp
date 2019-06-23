#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pi pair < int, int >

const int MAX = 1e4 + 5;
int n, a[MAX];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(cin >> n && n)
	{
		long long sum = 0, ans = 0;

		for(int i = 0; i < n; i ++)
			cin >> a[i];

		for(int i = 0; i < n; i ++)
		{
			if(sum + a[i] >= 0)
				sum += a[i];
			else
				sum = 0;

			ans = max(ans, sum);
		}


		if(ans)
			cout << "The maximum winning streak is " << ans << ".\n";
		else
			cout << "Losing streak.\n";
	}

	return 0;
}
