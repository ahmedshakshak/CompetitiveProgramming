#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pi pair < int, int >

vector < string > v;

const int MAX = 8;
int dx[] = {2, 2, -2, -2, -1, -1, 1, 1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
int a[MAX][MAX][MAX][MAX];
char r1, c1, r2, c2;

bool vaild(int x, int y)
{
	if(x >= 8 || x < 0 || y >= 8 || y < 0)
		return false;

	return true;
}

void solve()
{
	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j ++)
			for(int k = 0; k < MAX; k ++)
				for(int l = 0; l < MAX; l ++)
					if(i != k || j != l)
						a[i][j][k][l] = 1e5;

	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j ++)
			for(int k = 0; k < MAX; k ++)
				if(vaild(i + dx[k], j + dy[k]))
					a[i][j][i + dx[k]][j + dy[k]] = 1;

}

void floyd()
{
	solve();

	for(int i = 0; i < MAX; i ++)
		for(int j = 0; j < MAX; j ++)
			for(int k = 0; k < MAX; k ++)
				for(int l = 0; l < MAX; l ++)
					for(int m = 0; m < MAX; m ++)
						for(int o = 0; o < MAX; o ++)
						{
							if(k == m && l == o)
								continue;

							if(a[k][l][m][o] == 0)
								a[k][l][m][o] = a[k][l][i][j] + a[i][j][m][o];
							else
								a[k][l][m][o] = min(a[k][l][m][o], a[k][l][i][j] + a[i][j][m][o]);
						}

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//	freopen("output.txt", "w", stdout);

	floyd();

	while(cin >> r1 >> c1 >> r2 >> c2)
		cout << "To get from " << r1 << c1 << " to " << r2 << c2 << " takes " << a[r1 -'a'][c1 - '1'][r2 - 'a'][c2 - '1'] << " knight moves.\n";

	return 0;
}
