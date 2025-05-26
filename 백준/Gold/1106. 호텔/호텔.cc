#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;


int n,c;
int ans= 1e9;
vector<pair<int, int>>v;
int dp[2000];
int go(int here, int num)
{
	// 마을 다 돌면 끝이고
	if (here >= n)
	{
		return 0;
	}




}
// dp 에는 투자하는 돈의 최솟값
// dp[사람수]; 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> c>> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ b, a });
	}
	fill(dp, dp + 2000, 1e9);
	//sort(v.begin(), v.end());
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		dp[v[i].first] = min(v[i].second, dp[v[i].first]);
		for (int j = v[i].first; j < 2000; j++)
		{
			dp[j] = min(dp[j], dp[j - v[i].first] + v[i].second);
		}
	}

	for (int i = c; i < 2000; i++)
	{
		ans = min(dp[i], ans);
	}
	cout << ans;
	return 0;
}