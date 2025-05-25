#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>


using namespace std;


int n;
int dp[1500004];
vector<pair<int, int>>v;

int go(int here)
{
	if (here > n)
	{
		return 0;
	}

	int& ret = dp[here];
	if (ret != -1)
	{
		return ret;
	}


	ret = 0;
	
	ret = max(ret, go(here + 1));
	if (here + v[here].first <= n+1)
	{
		ret = max(ret,go(here + v[here].first) + v[here].second);
	}

	return ret;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.push_back({ 0, 0 });
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	memset(dp, -1, sizeof(dp));
	cout<<go(1);
	return 0;
}