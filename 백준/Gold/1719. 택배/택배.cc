#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int n, m;

int dist[1004][1004];
int p[1004][1004];
vector<pair<int, int>>v[204];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	fill(&dist[0][0], &dist[n + 1][m + 1], 1e9);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != 1e9)
			{
				p[i][j] = j;
			}
		}
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
					if (dist[i][j] > (dist[i][k] + dist[k][j]))
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						p[i][j] = p[i][k];
					}
				}
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (p[i][j] == 0)
			{
				cout << "- ";
				continue;
			}
			cout << p[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}