#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1, 0, -1 ,0 };

int n, m;
vector<vector<int>>v;
//vector<pair<int, int>>wall;
int dist[14][14];
queue<pair<int, int>>q;
vector<pair<int, int>>virus;

int ret = 0;
void bfs()
{

	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;


			if (dist[ny][nx] != 0)
			{
				continue;
			}
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] == 1)
			{
				continue;
			}

			dist[ny][nx] = 1;
			q.push({ ny, nx });
		}


	}

}

void go(int here, int cnt)
{
	if (cnt == 3)
	{
		for (pair<int, int> i : virus)
		{
			q.push({ i.first, i.second });
			dist[i.first][i.second] = 0;
		}
		memset(dist, 0, sizeof(dist));
		bfs();
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dist[i][j] == 0 &&v[i][j] == 0)
				{
					count++;
				}
			}
		}

		ret = max(count, ret);
		return;
	}

	for (int i = here; i < n * m; i++)
	{
		int y = i / m;
		int x = i % m;


		if (v[y][x] == 0)
		{
			v[y][x] = 1;
			//wall.push_back({ y, x });
			go(i + 1, cnt + 1);
			v[y][x] = 0;
			//wall.pop_back();
		}
		else
		{
			continue;
		}

	}
}


void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j];
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 2)
			{
				virus.push_back({ i , j });
			}
		}
	}
	go(0, 0);
	cout << ret;
	return 0;
}