#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dx[4] = { 0, 1,0 ,-1 };
int dy[4] = { 1,0,-1,0 };

bool visit[51][51];
vector<vector<char>>v1;
vector<vector<char>>v2;

int n, m, cnt= 0;
string s;


void dfs(int x, int y, char c1, char c2)
{
	visit[x][y] = true;
	v1[x][y] = c2;
	for (int i = 0; i < 4; i++)
	{
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}
		if (!visit[nx][ny])
		{
			if (v1[nx][ny] == c1)
			{
				v1[nx][ny] = c2;
				dfs(nx, ny, c1, c2);
			}
		}


	}
}

int main()
{
	cin >> n >> m;
	v1.resize(n, vector<char>(m));
	v2.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			v1[i][j] = s[j];
		}

	}	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			v2[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j])
			{
				dfs(i, j, v1[i][j], v2[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v1[i][j] == v2[i][j])
			{
				cnt++;
			}
		}
	}

	if (cnt == n * m)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}