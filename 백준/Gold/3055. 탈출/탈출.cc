#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace  std;

int dy[4] = { 0, 1,  0, -1 };
int dx[4] = { 1, 0, -1, 0 };


int r, c, hy, hx, by, bx;
vector<vector<char>>v;
vector<pair<int, int>>w;
int dist[54][54];

void print2()
{
	puts("");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << dist[i][j];
		}
		puts("");
	}
	puts("");
}


void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y, x });
	dist[y][x] = 0;

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
			if (v[ny][nx] != '.' && v[ny][nx] != 'D')
			{
				continue;
			}
			if (dist[ny][nx] <= dist[y][x] + 1)
			{
				continue;
			}
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

void bfsW(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y, x });
	dist[y][x] = 0;

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
			if (v[ny][nx] != '.')
			{
				continue;
			}
			if (dist[ny][nx] != 1e9)
			{
				continue;
			}
			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r>> c;
	v.resize(r, vector<char>(c));
	fill(&dist[0][0], &dist[r][c], 1e9);
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			v[i][j] = s[j];
			if (v[i][j] == 'S')
			{
				hy = i;
				hx = j;
			}
			if (v[i][j] == '*')
			{
				w.push_back({ i, j });
			}
			if (v[i][j] == 'D')
			{
				by = i;
				bx = j;
			}
		}
	}

	for (int i = 0; i < w.size(); i++)
	{
		bfsW(w[i].first, w[i].second);
	}
	//print2();
	bfs(hy, hx);
	//print2();
	if (dist[by][bx] == 1e9)
	{
		cout << "KAKTUS";
	}
	else
	{
		cout << dist[by][bx];
	}
	return 0;
}