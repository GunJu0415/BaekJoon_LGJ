#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m, a, b, c, d;
vector<vector<char>>v;
vector<vector<int>>dist;
void bfs(int y, int x)
{
	dist[y][x] = 0;
	deque<pair<int, int>>q;
	q.push_front({ y, x });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{

			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				continue;
			}
			if (dist[ny][nx] != -1)
			{
				continue;
			}
			if (v[ny][nx] != '0')
			{
				//v[ny][nx] = '0';
				dist[ny][nx] = dist[y][x] + 1;
				q.push_back({ ny, nx });
			}
			else
			{
				dist[ny][nx] = dist[y][x];
				q.push_front({ ny, nx });
			}

			
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> c >> d >> a >> b;
	v.resize(n, vector<char>(m));
	dist.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			v[i][j] = s[j];
		}
	}
	bfs(c - 1, d - 1);
	cout << dist[a - 1][b - 1];
	return 0;
}