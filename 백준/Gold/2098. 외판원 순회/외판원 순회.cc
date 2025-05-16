#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


int n;
int start;
int ans= 1e9;
int dp[17][1 << 17];
int dist[20][20];
int st;
int go(int node, int visit)
{
	if (visit == (1 << n) - 1)
	{
		if (dist[node][0] == 0)
		{
			return 1e9;
		}

		return dist[node][0];
	}

	if (dp[node][visit] != -1)
	{
		return dp[node][visit];
	}

	int result = 1e9;

	for (int i = 0; i < n; i++)
	{
		if (dist[node][i] == 0)
		{
			continue;
		}
		if (visit & (1 << i))
		{
			continue;
		}

		int newVisit = visit | (1 << i);

		result = min(go(i, newVisit) + dist[node][i], result);
	}
	return dp[node][visit] = result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	ans = min(ans, go(0, 1 << 0));

	cout << ans;
	return 0;
}