#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };
int n, m, cnt = 0, ans = 0;
vector<vector<int>>v;
bool visit[104][104];
int dist[104][104];
int starty, startx;

void print()
{
	puts("");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	puts("");
}

void printV()
{
	puts("");
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
		cout << v[i][j] << " ";
	}
	cout << "\n";
}
puts("");
}
void dfs(int y, int  x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
		{
			continue;
		}
		if (v[ny][nx] > 0 && v[y][x] == 0)
		{
			dist[ny][nx] += 1;
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		dfs(ny, nx);
	}
}

int  main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 0)
			{
				starty = i;
				startx = j;
			}
		}
	}

	//dfs(starty, startx);
	//print();		
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		if (dist[i][j] == 0)
	//		{
	//			//cnt++;
	//		}
	//		if (dist[i][j] > 1)
	//		{
	//			v[i][j] = 0;
	//		}
	//	}
	//}
	//puts("");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << v[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//puts("");
	while (cnt <n * m)
	{
		ans++;
		fill(&dist[0][0], &dist[n + 1][m + 1], 0);
		fill(&visit[0][0], &visit[n + 1][m + 1], 0);
		cnt = 0;
		dfs(0, 0);
		//print();
		//printV();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

				if (dist[i][j] > 1)
				{
					v[i][j] = 0;
				}
				if (v[i][j] == 0)
				{
					cnt++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}