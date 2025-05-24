#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;


int n;
vector<int>v;
int dp[1004];
int ret = 0;

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
			if (v[i] < v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
		ret = max(ret, dp[i]);
	}
	cout << ret;
	return 0;
}