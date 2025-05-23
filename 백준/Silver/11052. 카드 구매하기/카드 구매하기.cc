#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long  long int ll;
ll dp[1004];
ll n;
vector<ll>v;


void go()
{
	dp[1] = v[1];
	dp[2] = max(v[1] * 2, v[2]);
	//dp[3] = max(v[3], dp[2] + dp[1]);

	for (ll i = 3; i <= n; i++)
	{
		dp[i] = max(v[i], dp[i - 1] + dp[1]);
		if (i % 2 == 0)
		{
			dp[i] = max(dp[i], dp[i / 2] * 2);
		}
		else
		{
			dp[i] = max(dp[i], dp[i / 2] + dp[i/2+1]);
		}
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				dp[i] = max(dp[i], dp[j] * (i/j));
			}
			else
			{
				dp[i] = max(dp[i], dp[j] * (i / j) + dp[i % j]);
			}
		}
	}
	

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	v.push_back(0);
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		v.push_back(a);
	}
	go();
	cout << dp[n];
	return 0;
}