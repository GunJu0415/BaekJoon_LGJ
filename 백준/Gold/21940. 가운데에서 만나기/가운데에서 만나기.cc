#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int n, m;
int p;

int target, ret = 1e9;

int dist[304][304];
vector<int>v;
vector<int>ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	fill(&dist[0][0], &dist[n + 1][n + 1], 1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
				//	continue;
					dist[i][j] = 0;
				}
				if (dist[i][k] != 1e9 || dist[k][j] != 1e9)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}


	cin >> p;
	for (int i = 0; i < p; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 0; j < p; j++)
		{
			
			temp = max(dist[v[j]][i] + dist[i][v[j]], temp);
		}

		//cout << temp << " ";
		if (ret > temp)
		{
			ans.clear();
			ans.push_back(i);
			ret = temp;
			//target = i;
			//cout << i << " " << ret << " \n";
		}
		else if (ret == temp)
		{
			//cout << i << " " << ret << " \n";
			ans.push_back(i);
		}
	}

	for (int i : ans)
	{
		cout << i << " ";
	}

	return 0;
}