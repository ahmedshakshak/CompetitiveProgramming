#include <iostream>
using namespace std;
#define pi pair < int, int >
#define pli pair < long long, int >
#define pll pair < long long, long long >
#define f first
#define s second
#define MASK bitset < 20 >

const int MAX = 9;
int dx[] = {1, -1, 1, -1, 2, 2, -2, -2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};
int dist[MAX][MAX][MAX][MAX];
char x1, y1, x2, y2; // be careful of declaring y1 with " <bits/stdc++.h> or <math.h> " --->> compilation error 

bool vaild(int x, int y)
{
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

void floyed()
{
	for(int i = 0; i < 8; i ++)
		for(int j = 0; j < 8; j ++)
			for(int k = 0; k < 8; k ++)
				for(int l = 0; l < 8; l ++)
					dist[i][j][k][l] =  i == k && j == l ? 0 : 1e9;

	for(int i = 0; i < 8; i ++)
		for(int j = 0; j < 8; j ++)
			for(int k = 0; k < 8; k ++)
			{
				int x = dx[k] + i, y = dy[k] + j;

				if(vaild(x, y))
					dist[i][j][x][y] = 1;
			}

	for(int i = 0; i < 8; i ++)
		for(int j = 0; j < 8; j ++)
			for(int k = 0; k < 8; k ++)
				for(int l = 0; l < 8; l ++)
					for(int m = 0; m < 8; m ++)
						for(int n = 0; n < 8; n ++)
							dist[k][l][m][n] = min(dist[k][l][m][n], dist[k][l][i][j] + dist[i][j][m][n]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	floyed();

	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		x1 -= 'a', y1 -= '1', x2 -= 'a', y2 -= '1';
		cout << "To get from " << char(x1 + 'a') << char(y1 + '1') << " to " << char(x2 + 'a') << char(y2 + '1') << " takes " << dist[x1][y1][x2][y2] << " knight moves.\n";
	}

	return 0;
}
