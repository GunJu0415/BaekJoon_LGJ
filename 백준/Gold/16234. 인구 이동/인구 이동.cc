#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int dy[4] = { 0, 1,0 ,-1 };
int dx[4] = { 1, 0, -1, 0 };


int n, l, r;
vector<vector<int>>v;
vector<vector<int>>dist;
bool visit2[54][54];
int visit[54][54];
int ret = 0;
int temp = 0;
int sum = 0;
bool flag = 0;
void dfs(int y, int x, int num)
{
	//cout << y << " " << x <<" ";
	temp++;
	sum += v[y][x];
	visit[y][x] = num;
	//cout << visit[y][x] << "\n";
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || ny < 0 || nx >= n || nx < 0)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		int cnt = abs(v[ny][nx] - v[y][x]);
		if (cnt >= l && cnt <= r)
		{
			//flag = 1;
			//cout << v[y][x] <<" " << v[ny][nx] << " " << cnt << "  " << ny << " " << nx << " ";
			dfs(ny, nx, num);
		}
	}
}

void dfs2(int y, int x, int num, int cnt)
{
	dist[y][x] = num;
	visit2[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || ny < 0 || nx >= n || nx < 0)
		{
			continue;
		}
		if (visit[ny][nx] != cnt)
		{
			continue;
		}
		if (visit2[ny][nx])
		{
			continue;
		}
		//if (dist[ny][nx] == dist[y][x])
		//{
		//	continue;
		//}
		dfs2(ny, nx, num, cnt);
	}
}

void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visit[i][j] << " ";
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
	cin >> n;
	v.resize(n, vector<int>(n));
	dist.resize(n, vector<int>(n));

	cin >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			dist[i][j] = v[i][j];
		}
	}

	while (1)
	{
		flag = 0;
		int cnt = 1;
		dist = v;
		fill(&visit[0][0], &visit[0][0] + 54 * 54, 0); // 가장 안전

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

				if (!visit[i][j])
				{

					sum = 0;
					temp = 0;
					dfs(i, j, cnt);
					if (temp > 1)
					{
						fill(&visit2[0][0], &visit2[0][0] + 54 * 54, 0); // 가장 안전
						dfs2(i, j, sum / temp, cnt);
						flag = 1;
					}

					cnt++;
				}


			}
		}

		v = dist;

		if (!flag)
		{
			break;
		}
		ret++;

	}
	cout << ret;



	return 0;
}