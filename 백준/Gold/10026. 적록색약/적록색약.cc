#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;



vector<vector<char>> v;
vector<vector<bool>> visit;
vector<vector<bool>> visit2;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int n, cnt1 = 0, cnt2 = 0;


void bfs1(int x, int y, char color)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = dx[i] + x;
			int yy = dy[i] + y;


			if (xx >= n || xx < 0 || yy >= n || yy < 0)
			{
				continue;
			}

			if (!visit[xx][yy] && v[xx][yy] == color)
			{
				visit[xx][yy] = 1;
				q.push(make_pair(xx, yy));
			}

		}
	}
	cnt1++;
}

void bfs2(int x, int y, char color)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit2[x][y] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = dx[i] + x;
			int yy = dy[i] + y;


			if (xx >= n || xx < 0 || yy >= n || yy < 0)
			{
				continue;
			}
			if (color == 'R' || color == 'G')
			{
				if (!visit2[xx][yy] && v[xx][yy] == 'R')
				{
					visit2[xx][yy] = 1;
					q.push(make_pair(xx, yy));
				}
				if (!visit2[xx][yy] && v[xx][yy] == 'G')
				{
					visit2[xx][yy] = 1;
					q.push(make_pair(xx, yy));
				}
			}
			if (color == 'B')
			{

				if (!visit2[xx][yy] && v[xx][yy] == color)
				{
					visit2[xx][yy] = 1;
					q.push(make_pair(xx, yy));
				}
			}
		}
	}
	cnt2++;
}


int main()
{
	cin >> n;
	v.resize(n, vector<char>(n));
	visit.resize(n, vector<bool>(n));
	visit2.resize(n, vector<bool>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j])
			{
				bfs1(i, j, v[i][j]);
			}
			if (!visit2[i][j])
			{
				bfs2(i, j, v[i][j]);
			}
		}
	}

	cout << cnt1 << " " << cnt2;
	return 0;
}