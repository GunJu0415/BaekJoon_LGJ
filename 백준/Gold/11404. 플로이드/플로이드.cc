#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int n, m;

vector<vector<int>>v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(n+1, vector<int>(n+1, 1e9));

	//for (int i = 1; i <= n; i++)
	//{
	//	v[i][i] = 0;
	//}

	for (int i = 0; i < m; i++)
	{
		int  a, b, c;
		cin >> a >> b >> c;
		v[a][b] = min(v[a][b], c);
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
				if (v[i][k] != 1e9 && v[k][j] != 1e9)
				{
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (v[i][j] == 1e9)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << v[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}