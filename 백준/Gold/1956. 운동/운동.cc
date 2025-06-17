#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int v, e;
int dist[404][404];
int ret = 1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e;
	fill(&dist[0][0], &dist[v + 1][v + 1], 1e9);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				if (i == j)
				{
					continue;
				}
				if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j)
			{
				continue;
			}

			ret = min(ret, dist[i][j] + dist[j][i]);
		}
	}
	if (ret == 1e9)
	{
		cout << -1;
		return 0;
	}
	cout << ret;

}