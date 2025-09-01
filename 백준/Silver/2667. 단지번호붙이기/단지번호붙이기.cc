#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<int>>v;
vector<int> v2;
bool visit[100][100];
int n, cnt = 0, t= 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int x, int y)
{
	cnt++;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int xx = dx[i] + x;
		int yy = dy[i] + y;

		if (xx >= n || xx < 0 || yy >= n || yy < 0)
		{
			continue;
		}
		if (visit[xx][yy] || v[xx][yy] == 0)
		{
			continue;
		}
		if (!visit[xx][yy])
		{
			visit[xx][yy] = true;
			dfs(xx, yy);
		}
		
	}
}
int main() 
{
	cin >> n;
	v.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visit[i][j] && v[i][j]  == 1)
			{
				dfs(i, j);
				v2.push_back(cnt);
				t++;
				cnt = 0;
			}
		}
	}
	cout << t;
	puts("");
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << "\n";
	}
	return 0;
}