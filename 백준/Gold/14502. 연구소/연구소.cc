#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
//vector<vector<int>>v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<pair<int, int>>v;
bool visit[100][100];
vector<vector<int>>map;
vector<vector<int>>dist;
vector<pair<int, int>>virus;
int n, m,ans;
void bfs(int y, int x)
{
	queue<pair<int, int>>q;

	q.push({ y, x });
	visit[y][x] = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n||ny < 0 || nx >= m || nx < 0)
			{
				continue;
			}
			if (visit[ny][nx])
			{
				continue;
			}
			if (map[ny][nx] == 1)
			{
				continue;
			}
			if (map[ny][nx] == 0)
			{
				map[ny][nx] = 2;
			}
			visit[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}
}
void go(int idx)
{
	if (v.size() == 3)
	{
		map = dist;
		for (int i =0;i<3;i++)
		{
			map[v[i].first][v[i].second] = 1;
		}

		for(int i =0;i<virus.size();i++)
		{
			memset(visit, 0, sizeof(visit));
			bfs(virus[i].first, virus[i].second);
		}		

		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//cout << map[i][j];
				if (map[i][j] == 0)
				{
					temp++;
				}
			}
			//puts("");
		}
		//puts("");
		ans = max(ans, temp);

		return;
	}
	for (int i = idx; i < n * m; i++)
	{
		int y = i / m;
		int x = i % m;
		if (dist[y][x] == 0)
		{
			v.push_back({ y,x });
			go(i+1);
			v.pop_back();
		}

	}
}
int main()
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	dist.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			dist[i][j] = map[i][j];
			if (map[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}

	go(0);

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << map[i][j];
	//	}
	//	puts("");
	//}
	cout << ans;
	return 0;
}