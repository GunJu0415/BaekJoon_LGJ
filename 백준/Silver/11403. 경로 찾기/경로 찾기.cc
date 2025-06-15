#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n;

int dist[104][104];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	fill(&dist[0][0], &dist[n + 1][n + 1], 1e9);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			dist[i][j] = min(dist[i][j], a);
			//dist[j][i] = min(dist[j][i], a);
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dist[i][k] != 0 && dist[k][j] != 0)
				{
					dist[i][j] = 1;
				}
			}
		}
	}
	//cout << "==========================================================\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//if (dist[i][j] == 1e9)
			//{
			//	cout << 0 << " ";
			//	continue;
			//}
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}