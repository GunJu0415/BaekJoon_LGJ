#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>



using namespace std;

int dy[4] = { 0, 1,0 ,-1 };
int dx[4] = { 1, 0, -1, 0 };

int n;
int ret = 1e9;
vector<vector<int>>v;
vector<vector<pair<int, int>>>land;
vector<pair<int, int>>temp;
bool visit[104][104];
int dist[104][104];
//int lp[104][104];
void dfs(int y, int x, int c)
{
	//v[y][x] = c;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || ny < 0 || nx >= n || nx < 0)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		if (v[ny][nx] == 0)
		{
			v[y][x] = c;
			continue;
		}

		dfs(ny, nx, c);

	}
}

void bfs(int y, int x, int c)
{
	visit[y][x] = 1;
	queue<pair<int, int>>q;
	q.push({ y, x });
	dist[y][x] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || ny < 0 || nx >= n || nx < 0)
			{
				continue;
			}

			if (dist[ny][nx] != 1e9)
			{
				continue;
			}
			if (v[ny][nx] == 1)
			{
				continue;
			}
			if (v[ny][nx] == c)
			{
				continue;
			}
			if (v[ny][nx] != 0)
			{
				ret = min(ret, dist[y][x]);
			}
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout <<  v[i][j] <<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void print2()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 1e9)
			{
				cout << "N" << " ";
			}
			else
			{
				cout << dist[i][j] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	// 섬 구별
	int num = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 1 && !visit[i][j])
			{
				dfs(i, j, num);
				num++;
			}
		}
	}
	//print();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fill(&dist[0][0], &dist[n+1][n+1], 1e9);
			if (v[i][j] != 0 && v[i][j] != 1)
			{
				bfs(i, j, v[i][j]);
				//print2();
			}
		}
	}
	cout << ret;
	//print();
	//print2();
	return 0;
}