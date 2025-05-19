#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int n;

int dp[1000004];


void go()
{

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	go();
	cout << dp[n];
	return 0;
}