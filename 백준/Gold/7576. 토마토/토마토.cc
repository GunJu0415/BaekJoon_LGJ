#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


queue<pair<int, int>> q;
vector<vector<int>>v;
bool visit[1004][1004];


int n, m, z = 0;

void bfs()
{

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = true;
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= m || nx < 0 || ny >= n || ny < 0)
			{
				continue;
			}

			if (v[nx][ny] != 0)
			{
				continue;
			}
			
			if (!visit[nx][ny])
			{
				visit[nx][ny] = true;
				v[nx][ny] = v[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

}

int main()
{
	int a = 0, b = 0;
	cin >> n >> m;

	v.resize(m, vector<int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 1)
			{
				z++;
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();

	int max = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 0)
			{
				max = 0;
				break;
			}
			if (max <= v[i][j])
			{
				max = v[i][j];
			}
		}
		if (max == 0)
		{
			break;
		}
	}

	max -= 1;
	cout << max;
	return 0;
}