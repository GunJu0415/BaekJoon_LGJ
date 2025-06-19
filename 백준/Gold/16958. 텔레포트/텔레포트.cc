#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int n, t,m;


vector<pair<pair<int, int>, int>>v;
vector<pair<pair<int, int>, pair<int, int>>>citys;

int dist[1004][1004];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> t;
	fill(&dist[0][0], &dist[n + 1][n + 1], 1e9);
	v.push_back({ {0,0}, 0 });
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ {b, c}, a });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (v[i].second == 1 && v[j].second == 1)
			{
				dist[i][j] = min(dist[i][j], t);
				dist[j][i] = min(dist[j][i], t);
				//dist[i][j] = min(dist[i][j], (abs(v[i].first.first - v[j].first.first)) + (abs(v[i].first.second - v[j].first.second)));
				//dist[j][i] = min(dist[j][i], (abs(v[i].first.first - v[j].first.first)) + (abs(v[i].first.second - v[j].first.second)));
				//continue;
			}
			dist[i][j] = min(dist[i][j], (abs(v[i].first.first - v[j].first.first)) + (abs(v[i].first.second - v[j].first.second)));
			dist[j][i] = min(dist[j][i], (abs(v[i].first.first - v[j].first.first)) + (abs(v[i].first.second - v[j].first.second)));
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
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cout << dist[a][b] << "\n";
	}

	return 0;
}