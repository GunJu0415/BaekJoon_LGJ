#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

vector<int>v;

int n;
int dp[1004];
int dp2[1004];
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
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = n-1; i >= 0; i--)
	{
		dp2[i] = 1;
		for (int j = n -1; j > i; j--)
		{
			if (v[i] > v[j])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		ret = max(dp[i] + dp2[i] - 1, ret);
		//cout << dp[i];
		//cout << dp2[i];
	}
	cout << ret;

	return 0;
}