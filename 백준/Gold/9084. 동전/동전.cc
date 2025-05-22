#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>



using namespace std;

typedef long long int ll;
ll n, m, t;
ll dp[10004];
vector<int>v;


void go()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= m; j++)
		{
			if (j == v[i])
			{
				dp[j] += 1;
			}
			else
			{
				dp[j] += dp[j - v[i]];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--)
	{
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		cin >> m;

		memset(dp, 0, sizeof(dp));
		go();
		cout << dp[m] <<"\n";

	}
	return 0;
}