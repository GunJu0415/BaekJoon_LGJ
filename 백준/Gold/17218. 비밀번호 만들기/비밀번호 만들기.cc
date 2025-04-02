#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

string s1, s2;

int dp[1004][1004];
int ans  =0;
vector<char>result;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s1 >> s2;
	if (s1 < s2)
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	s1 = " " + s1;
	s2 = " " + s2;
	//cout << s1 << "\n" << s2 << "\n";
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
		}
	}
	int i = s1.size() - 1;
	int j = s2.size() - 1;
	while(i > 0 && j > 0)
	{
			if (dp[i - 1][j] == dp[i][j])
			{
				i = i - 1;
			}
			else if (dp[i][j - 1] == dp[i][j])
			{
				j = j - 1;
			}
			else
			{
				result.push_back(s1[i]);
				i = i-1;
				j = j - 1;
			}
	}
	reverse(result.begin(), result.end());
	for (char i : result)
	{
		cout << i;
	}
	//cout << dp[s1.size() - 1][s2.size() - 1];
	return 0;
}