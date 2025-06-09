#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int dy[4] = { 0, 1,0 ,-1 };
int dx[4] = { -1 ,0,1,0 };

int dist[5][104][104];

int visit[5][104][104];
int r, c;
int ret = 1e9;
map<int, int>mp;
vector<vector<int>>v;
vector<pair<int, int>>enemy;

void bfs(int num, int y, int x)
{
	queue<pair<int, int>>q;
	dist[num][y][x] = 0;
	q.push({ y, x });
	visit[num][y][x] = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= r || ny < 0 || nx >= c || nx < 0)
			{
				continue;
			}
			if (dist[num][ny][nx] != 1e9)
			{
				continue;
			}
			if (v[ny][nx] == 1)
			{
				continue;
			}
			visit[num][ny][nx] = 1;
			dist[num][ny][nx] = 1 + dist[num][y][x];
			q.push({ ny, nx });
		}
	}
}
void print2()
{
	cout << "\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << v[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
void print()
{
	cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				if (dist[i][j][k] == 1e9)
				{
					cout << "*";
					continue;
				}
				cout<<dist[i][j][k];
			}
			cout << "\n";
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
	cin >> r >> c;
	v.resize(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}
	fill(&dist[0][0][0], &dist[4][r + 1][c + 1], 1e9);
	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		enemy.push_back({ a, b });
		bfs(i, a, b);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visit[0][i][j] && visit[1][i][j] && visit[2][i][j])
			{
				
				int temp = 0;
				temp= max(dist[2][i][j], max(dist[0][i][j], dist[1][i][j]));
				ret = min(temp, ret);
				if (ret == temp)
				{
					mp[ret]++;
				}

				
			}
		}
	}
	//print();
	if (ret == 1e9)
	{
		cout << -1;
		return 0;
	}
	cout << ret<<"\n";
	cout << mp[ret];
	//print();
	return 0;
}