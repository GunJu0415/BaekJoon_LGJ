#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0,  -1, 0 };


int n, m;
int chcnt = 0;
int ret = 1e9;
vector<vector<int>>v;
int dist[54][54];
vector<pair<int, int>>ch;
vector<pair<int, int>>home;
queue<pair<int, int>>q;
vector<pair<int, int>>temp;


void bfs()
{
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
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}

}

void go(int here)
{
	if (temp.size() == m)
	{
		int sum = 0;
		fill(&dist[0][0], &dist[n + 1][n + 1], 1e9);
		for (auto i : temp)
		{
			q.push({ i.first, i.second });
			dist[i.first][i.second] = 0;
		}
		bfs();
		for (auto i : home)
		{
			sum += dist[i.first][i.second];
		}
		ret = min(ret, sum);

		return;
	}

	for (int i = here; i < ch.size(); i++)
	{

		temp.push_back({ ch[i].first, ch[i].second });
		go(i + 1);
		temp.pop_back();
	}

}


void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 1e9)
			{
				cout << 0 << " ";
				continue;
			}
			cout << dist[i][j] << " ";
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
	cin >> n >> m;
	//fill(&dist[0][0], &dist[n + 1][n + 1], 1e9);
	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 1)
			{
				home.push_back({ i, j });
				//dist[i][j] = 0;
			}
			if (v[i][j] == 2)
			{
				chcnt++;
				ch.push_back({ i, j });
			}
		}
	}
	//chcnt = chcnt - m;
	//bfs();
	//print();
	go(0);
	cout << ret;
	return 0;
}