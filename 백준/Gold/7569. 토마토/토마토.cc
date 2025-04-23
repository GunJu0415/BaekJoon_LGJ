#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dh[3] = { 0, 1, -1 };
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int n, m, H, maxday, tocnt = 0;
int dist[104][104][104];
vector<vector<vector<int>>>v;
queue<pair<int, pair<int, int>>>q;
void print()
{
	cout << "\n";
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (dist[i][j][k] == 1e9)
				{
					cout << -1 << " ";
					continue;
				}
				cout << dist[i][j][k] << " ";
			}
			cout << "\n";
		}

	}
	cout << "\n\n";
}
void bfs()
{
	//queue<pair<int, pair<int, int>>>q;
	//q.push({ h, {y, x} });
	
	while (!q.empty())
	{
		//print();
		int h = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();

		if (H > 1)
		{
			for (int i = 0; i < 3; i++)
			{
				int nh = h + dh[i];
				if (nh >= H || nh < 0)
				{
					continue;
				}
				if (dist[nh][y][x] != 1e9)
				{
					continue;
				}
				if (v[nh][y][x] == -1)
				{
					continue;
				}
				dist[nh][y][x] = dist[h][y][x] + 1;
				tocnt--;
				maxday = max(maxday, dist[nh][y][x]);
				q.push({ nh,{y, x} });
			}
		}
		for (int j = 0; j < 4; j++)
		{
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny >= m || ny < 0 || nx >= n || nx < 0)
			{
				continue;
			}
			if (dist[h][ny][nx] != 1e9)
			{
				continue;
			}
			if (v[h][ny][nx] == -1)
			{
				continue;
			}
			dist[h][ny][nx] = dist[h][y][x] + 1;
			tocnt--;
			maxday = max(dist[h][ny][nx], maxday);
			q.push({ h, {ny, nx} });
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> H;
	v.resize(H, vector<vector<int>>(m, vector<int>(n)));
	fill(&dist[0][0][0], &dist[H][n][m], 1e9);
	for (int i = 0; i <H; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> v[i][j][k];
				if (v[i][j][k] == 1)
				{
					dist[i][j][k] = 0;
					q.push({ i, {j, k} });
				}
				if (v[i][j][k] == 0)
				{
					tocnt++;
				}
			}
		}
	}
	bfs();
	if (tocnt != 0)
	{
		cout << -1;
		return 0;
	}
	cout << maxday;
	return 0;
}