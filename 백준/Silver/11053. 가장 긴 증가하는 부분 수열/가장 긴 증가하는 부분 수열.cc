#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n, ret = 0;
int dp[1004];
vector<int>v;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(dp[i], ret);

	}
	cout << ret;

	return 0;
}