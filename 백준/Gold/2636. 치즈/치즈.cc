#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>



using namespace std;



int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int n, m, t = 0, cnt = 0, temp = 0;
vector<vector<int>>v;
vector<vector<int>> dist;
bool visit[104][104];

void print()
{
	puts("");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		puts("");
	}
	puts("");
}
void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y,x });
	visit[y][x] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny >= n || ny < 0 || nx >= m || nx<0)
			{
				continue;
			}
			if (visit[ny][nx])
			{
				continue;
			}

			if (v[ny][nx] == 1)
			{
				dist[ny][nx] = 0;
				continue;
			}
			visit[ny][nx] = 1;
			q.push({ ny, nx });
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
	dist.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			dist[i][j] = v[i][j];
			if (v[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	//int a = 10;
	while (cnt < n*m)
	{
		//print();
		t++;
		fill(&visit[0][0], &visit[n][m], 0);
		temp = (n * m) - cnt;
		cnt = 0;
		bfs(0, 0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (dist[i][j] == 0)
				{
					cnt++;
				}
			}
		}
		v = dist;
	}

	cout << t << "\n" << temp;
	return 0;
}