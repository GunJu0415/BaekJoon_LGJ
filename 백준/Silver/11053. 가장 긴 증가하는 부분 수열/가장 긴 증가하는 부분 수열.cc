#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int n, ans=0;
int dp[1004][1004];
vector<int>v;
int go(int x, int num)
{
	
	if (x == n)
	{
		return 0;
	}

	int& ret = dp[x][num];
	if (ret != - 1)
	{
		return ret;
	}
	ret = go(x + 1, num);
	if (v[x] > num)
	{
		ret = max( ret, go(x + 1, v[x]) + 1);
	}
	return ret;
	
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0);
	return 0;
}