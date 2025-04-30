#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dy[8] = { 0, 1, 0, - 1, 1, 1, -1,-1 };
int dx[8] = { 1, 0, -1,0, -1, 1, -1, 1 };

int n, m;
vector<vector<int>>v;
queue<pair<int, int>>q;
int dist[54][54];
int ans = 0;

void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}cout << "\n";
}
void bfs()
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= n || ny < 0 || nx >= m || nx < 0)
			{
				continue;
			}
			//if(v[ny][nx] == 1)
			if (dist[ny][nx]  <= dist[y][x] +1)
			{
				continue;
			}

			dist[ny][nx] = dist[y][x] + 1;
			ans = max(dist[ny][nx], ans);
			q.push({ ny,nx });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	fill(&dist[0][0], &dist[n + 1][m + 1], 1e9);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 1)
			{
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}
	bfs();
	//print();
	cout << ans;
	return 0;
}
