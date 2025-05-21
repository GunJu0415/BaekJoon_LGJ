#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int dp[1004];
int n;
vector<int>v;
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
		dp[i] = v[i];
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				dp[i] = max(dp[i], dp[j] + v[i]);
			}
		}
		ret = max(dp[i], ret);
	}

	cout << ret;

	return 0;
}