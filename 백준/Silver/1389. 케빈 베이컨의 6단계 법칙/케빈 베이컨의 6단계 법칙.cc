#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n, m;
vector<int>v[104];
int dist[104][104];
int ans = 1e9;
int ret = 1e9;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	fill(&dist[0][0], &dist[n + 1][n + 1],  1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
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
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			//cout << dist[i][j] << " ";
			temp += dist[i][j];
		}
		//cout << "\n";
		if (ret > temp)
		{
			ret = temp;
			ans = i;
		}
		else if (ret == temp)
		{
			ans = min(ans, i);
		}
	}
	cout << ans;
	return 0;
}