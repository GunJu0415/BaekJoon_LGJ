#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
int n;
int comp[24];
int asum = 0;
int bsum = 0;
int ans = 1e9;
int ateamcnt = 0;
vector<vector<int>>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.resize(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		memset(comp, 0, sizeof(comp));
		ateamcnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				ateamcnt++;
			}
		}
		asum = 0;
		bsum = 0;

		if (ateamcnt == n / 2)
		{
			for (int j = 1; j <= n; j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (comp[j] == 1 && comp[k] == 1)
					{
						asum += v[j][k];
					}
					else if (comp[k] == 0 && comp[j] == 0)
					{
						bsum += v[j][k];
					}
					else
					{
						continue;
					}
				}
			}
			ans = min(ans, abs(asum - bsum));
		}
	}
	cout << ans;

	return 0;
}