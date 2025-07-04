#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int t;
int n, m, K;
int dist[104][104];
vector<int>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--)
	{
		int ret = 1e9, ans;
		cin >> n >> m;
		v.clear();
		fill(&dist[0][0], &dist[103][103], 1e9);

		for (int i = 1; i <= n; i++)
		{
			dist[i][i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			dist[a][b] = min(dist[a][b], c);
			dist[b][a] = min(dist[b][a], c);
		}

		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (dist[i][k] != 1e9 && dist[k][j] != 1e9)
					{
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[j][k]);
					}
				}
			}
		}
		cin >> K;
		for (int i = 0; i < K; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}

		for (int i = 1; i <= n; i++)
		{
			int flag = 0;
			int temp = 0;
			for (int j = 0; j < K;j++)
			{
				temp += dist[v[j]][i];
			}
			if (temp < ret)
			{
				ans = i;
				ret = temp;
			}
		}
		cout << ans <<"\n";

	}
	return 0;
}