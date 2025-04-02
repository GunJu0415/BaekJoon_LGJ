#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

string s1, s2;

int dp[1004][1004];
int ans  =0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;

	dp[0][0] = 0;
	for (int i = 1; i < s1.size(); i++)
	{
		for (int j = 1; j < s2.size(); j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if (s1[i] == s2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}