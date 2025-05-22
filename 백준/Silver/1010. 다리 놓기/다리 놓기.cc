#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>



using namespace std;



int n, m, t;
int dp[34][34];

int go(int here, int num)
{
	if (here == n-1)
	{
		return 1;
	}

	int& ret = dp[here][num];
	if (ret != -1)
	{
		return ret;
	}

	ret = 0;
	for (int i = num+1; i < m; i++)
	{
		ret += go(here + 1, i);
	}

	return ret;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(dp, -1, sizeof(dp));
		int sum = 0;
		for (int i = 0; i < m; i++)
		{
			sum += go(0, i);
		}
		cout << sum << "\n";
	}

	return 0;
}