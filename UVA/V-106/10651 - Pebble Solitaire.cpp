#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pi pair < int, int >
typedef bitset< 12 > MASK;

map < int, int > memo;
MASK mask;

int fn(MASK mask)
{
	int &ret = memo[mask.to_ulong()];

	if(ret != 0)
		return max(ret, 0);

	for(int i = 0; i <= 11; i ++)
	{
		if(i + 2 <= 11 && mask[i] == 1 && mask[i + 1] == 1 && mask[i + 2] == 0)
		{
			auto tmask = mask;
			tmask[i] = tmask[i + 1] = 0;
			tmask[i + 2] = 1;
			ret = max(ret, 1 + fn(tmask));
		}

		if(i - 1 >= 0 && mask[i] == 1 && mask[i + 1] == 1 && mask[i - 1] == 0)
		{
			auto tmask = mask;
			tmask[i] = tmask[i + 1] = 0;
			tmask[i - 1] = 1;
			ret = max(ret, 1 + fn(tmask));
		}
	}

	if(ret == 0)
		ret = -1;

	return max(ret, 0);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("output.txt", "w", stdout);
	int t;
	char x;
	cin >> t;

	while(t--)
	{
		int n = 0;
		mask = 0;
		memo.clear();

		for(int i = 0; i < 12; i ++)
		{
			cin >> x;

			if(x == 'o')
			{
				mask[i] = 1;
				n++;
			}
		}

		cout << n - fn(mask) << "\n";
	}

	return 0;
}

