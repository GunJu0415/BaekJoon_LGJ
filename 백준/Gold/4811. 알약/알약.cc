#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long int ll;

ll n;

ll dp[1000][1000];

ll go(ll cap, ll half)
{
	if (cap < 0)
	{
		return 0;
	}
	if (half < 0)
	{
		return 0;
	}
	if (cap == 0 && half == 0)
	{
		return 1;
	}

	ll& ret = dp[cap][half];
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;
	// 반개 짜리 먹었을때
	ret = go(cap, half - 1) + go(cap - 1, half + 1);

	// 한개 짜리 골라서 반개짜리 먹고 반개짜리 넣었을때
	//ret += ;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (1)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		fill(&dp[0][0], &dp[n + 1][n + 1], -1);
		//memset(dp, -1, sizeof(dp));
		cout << go(n - 1, 1) <<"\n";
	}
	
	return 0;
}