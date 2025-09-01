#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>


using namespace std;


int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int n, m;
int cnt = 0;
int ret = 0;
int ans = 0;
vector<vector<int>>v;
bool dist[1004][1004];
queue<pair<int, int>>q;


void bfs()
{
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		ret++;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= m || ny < 0 || nx >= n || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] != 0)
			{
				continue;
			}
			
			v[ny][nx] = v[y][x] + 1;
			ans = max(v[ny][nx], ans);
			q.push({ ny, nx });


		}

	}

}
void print()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v[i][j] << " ";
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
	v.resize(m, vector<int>(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 1)
			{
				q.push({ i, j });
				cnt++;
			}
			if (v[i][j] == 0)
			{
				cnt++;
			}
		}
	}

	bfs();
	//print();
	if (cnt == ret)
	{
		if (ans == 0)
		{
			cout << ans;
		}
		else
		{

			cout << ans - 1;
		}
	}
	else
	{

		cout << -1;
	}

	return 0;
}