#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp[104][104][104];
string s1, s2, s3;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s1 >> s2 >> s3;

	s1 = " " + s1;
	s2 = " " + s2;
	s3 = " " + s3;


	for (int i = 1; i < s1.size(); i++)
	{
		for (int j = 1; j < s2.size(); j++)
		{
			for (int k = 1; k < s3.size(); k++)
			{
				if (i == 0 || j == 0 || k == 0)
				{
					dp[i][j][k] = 0;
				}
				else if (s1[i] == s2[j] && s1[i] == s3[k])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}

	cout << dp[s1.size() - 1][s2.size() - 1][s3.size() - 1];

	return 0;
}