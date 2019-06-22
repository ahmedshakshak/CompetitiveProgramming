#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pi pair < int, int >

const int MAX = 25, moves = 4;
int n, m, x, y;
char a[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

void fix(int &x)
{
	x = ((x % m) + m) % m;
}

bool vaild(int r, int c)
{
	if(r < 0 || c < 0 || r >= n || c >= m || a[r][c] != a[x][y] || visited[r][c])
		return false;

	return true;
}

int mark(int r, int c)
{
	fix(c);

	if(!vaild(r, c))
		return 0;

	visited[r][c] = true;
	int ans = 1;

	for(int i = 0; i < moves; i ++)
		ans += mark(r + dx[i], c + dy[i]);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(cin >> n >> m)
	{
		int ans = 0;
		memset(visited, false, sizeof(visited));

		for(int i = 0;i < n; i ++)
			for(int j = 0; j < m; j ++)
				cin >> a[i][j];

		cin >> x >> y;
		mark(x, y);

		for(int i = 0; i < n; i ++)
			for(int j = 0;j < m; j++)
				if(!visited[i][j])
					ans = max(ans, mark(i, j));

		cout << ans << "\n";
	}

	return 0;
}
