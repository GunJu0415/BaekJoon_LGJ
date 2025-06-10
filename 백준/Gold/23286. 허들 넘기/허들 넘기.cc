#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;




int n, m, t;

vector<pair<int, int>>v[304];
bool visit[304];
int ed;
int st;
int ret = 1e9;
int dist[304][304];
//void dfs(int x, int cnt)
//{
//	if (x == ed)
//	{
//		ret = min(ret, cnt);
//	}
//	visit[x] = 1;
//	for (auto i : v[x])
//	{
//		if (visit[i.first])
//		{
//			return;
//		}
//
//		int temp = 0;
//		temp = max(i.second, cnt);
//		dfs(i.first, temp);
//		visit[i.first] = 0;
//	}
//
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> t;
	fill(&dist[0][0], &dist[n + 1][m + 1], 1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		v[a].push_back({ b, c });
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
				{
					dist[i][j] = min(max(dist[i][k], dist[k][j]), dist[i][j]);
				}
			}
		}
	}
	while (t--)
	{
		cin >> st;
		cin >> ed;
		// = 1e9;
		//memset(visit, 0, sizeof(visit));
		//dfs(st, ed);
		if (dist[st][ed] == 1e9)
		{
			cout << -1<<"\n";
			continue;
		}
		
		cout << dist[st][ed] <<"\n";
	}
	return 0;
}