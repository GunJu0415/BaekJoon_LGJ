#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int dx[4] = { 0, 1,0 ,-1 };
int dy[4] = { 1, 0, -1 ,0 };


int n, m;
int aans = 0, bans =0, ans = 1e9;
vector<vector<char>>v1, v2, v3;
bool visit[54][54];
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v2[i][j])
			{
				cout << v2[i][j];
			}
			else
			{
				cout << "O";
			}
			
		}
		puts("");
	}
	puts("");
}/*

void bfs(int y, int x, char c)
{
	visit[y][x] = 1;
	queue<pair<int, int>>q;
	q.push({ y, x });
	if (v1[y][x] != c)
	{
		aans++;
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m||nx < 0)
			{
				continue;
			}
			if (visit[ny][nx])
			{
				continue;
			}

			v2[ny][nx] = c;
			if (c == 'W')
			{
				c = 'B';
			}
			else if (c == 'B')
			{
				c = 'W';
			}
			visit[ny][nx] = 1;
			if (v1[ny][nx] != c)
			{
				aans++;
			}
			q.push({ ny, nx });
		}
		print();
	}
}*/

void makech(int y, int x, char c)
{
	//print();
	visit[y][x] = 1;
	if (c == 'W')
	{
		v2[y][x] = 'W';
		v3[y][x] = 'B';
	}
	else
	{
		v2[y][x] = 'B';
		v3[y][x] = 'W';

	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n||ny<0||nx>=m||nx<0)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		if (c == 'W')
		{
			makech(ny, nx, 'B');
		}
		else if (c == 'B')
		{
			makech(ny, nx, 'W');
		}
	}
}

void dfs(int y, int x,int nn, int mm, int starty, int startx)
{
	//print();
	visit[y][x] = 1;
	if (v1[y][x] != v2[y][x])
	{
		//cout << " asdf";
		aans++;
	}

	if (v1[y][x] != v3[y][x])
	{
		bans++;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= nn || ny < starty || nx >= mm||nx < startx)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		dfs(ny, nx, nn, mm, starty, startx);
	}
}

int main()
{
	cin >> n >> m;
	v1.resize(n, vector<char>(m));
	v2.resize(n, vector<char>(m));
	v3.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		char c = 'W';
		for (int j = 0; j < m; j++)
		{
			v1[i][j] = s[j];
		}
	}
	memset(visit, 0, size(visit));
	makech(0, 0, 'W');
	memset(visit, 0, size(visit));

	for (int i = 0; i < n - 7; i++)
	{
		for (int j = 0; j < m - 7; j++)
		{
			aans = 0;
			bans = 0;
			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					if (v2[k][l] != v1[k][l])
					{
						aans++;
					}
					if (v3[k][l] != v1[k][l])
					{
						bans++;
					}
				}
			}
			//memset(visit, 0, size(visit));
			//bans = 0, aans = 0;
			//dfs(i, j, i + 8, j + 8, i, j);
			//cout << aans << " " << bans << "\n";
			ans = min(ans, min(bans, aans));
		}
	}
	//puts("");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << v2[i][j];
	//	}
	//	puts("");
	//}
	//puts("");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << v3[i][j];
	//	}
	//	puts("");
	//}
	//dfs(0, 0,n, m, 0, 0);
	//cout << aans << " " << bans << "\n";
	//ans = min(ans, min(bans, aans));
	cout << ans;
	return 0;
}