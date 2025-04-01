#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int dx[4] = { 0, 1,0, - 1 };
int dy[4] = { 1, 0, -1, 0 };
int ans = 0;
int n, m;
vector<vector<char>>v;
int visit[100][100];
int dist[100][100];

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
void bfs(int y, int x)
{
	int a = y;
	int b = x;
	visit[y][x] = 1;
	dist[y][x] = 0;
	queue<pair<int, int>>q;
	q.push({ y, x });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0 )
			{
				continue;
			}
			if (v[ny][nx] != 'L')
			{
				continue;
			}
			if (visit[ny][nx])
			{
				continue;
			}
			visit[ny][nx] =1;
			dist[ny][nx] = dist[y][x] + 1;
			ans = max(dist[ny][nx], ans);
			//dist[ny][nx] = max(dist[a][b], dist[ny][nx]);
			q.push({ ny,nx });
			//print();
		}
	}
}
int main()
{
	cin >> n >> m;
	v.resize(n, vector<char>(m));
	//dist.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			v[i][j] = s[j];
		}
	}
	//puts("");

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] != 'W')
			{
				memset(visit, 0, sizeof(visit));
				memset(dist, 0, sizeof(dist));
				bfs(i, j);
				//print();

			}
		}
	}


	cout << ans;
	return 0;
}