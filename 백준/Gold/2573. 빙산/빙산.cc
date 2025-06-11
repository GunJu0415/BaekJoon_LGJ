#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int dx[4] = { 0, 1, 0,-1 };
int dy[4] = { 1, 0, -1, 0 };

int n, m, cnt =0,t=0, ice = 0, top= 0;
vector<vector<int>>v, temp;
bool visit[301][301];
void dfs(int y, int x)
{
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
		{
			continue;
		}
		if (v[ny][nx] == 0)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		visit[ny][nx] = true;
		dfs(ny, nx);
	}

}
void checkIce(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
		{
			continue;
		}
		if (v[ny][nx] == 0)
		{
			ice++;
		}
	}
}
int main()
{
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m ; j++)
		{
			cin >> v[i][j];
			top = max(v[i][j], top);
		}
	}
	temp = v;
	while (top <= n*m)
	{
		cnt = 0;
		top = 0;
		//puts("");
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visit[i][j] && v[i][j] != 0)
				{
					dfs(i, j);
					cnt++;
					//cout << cnt << " ";
				}
				else
				{
					top++;
				}
			}
			//puts("");
		}
		if (top == n * m)
		{
			break;
		}
		if (cnt >= 2)
		{
			break;
		}
		//puts("");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//cout << temp[i][j] << " ";
				if (v[i][j] != 0)
				{
					ice = 0;
					checkIce(i, j);
					temp[i][j] = max(temp[i][j] - ice, 0);
				}
			}
			//puts("");
		}
		v = temp;
		t++;
	}
	if (cnt < 2)
	{
		cout << 0;
	}
	else
	{
		cout << t;
	}

	return 0;
}