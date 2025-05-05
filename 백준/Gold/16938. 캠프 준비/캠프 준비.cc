#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int n, l, r, x;
int ret = 0;
vector<int>v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> l >> r>>x;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 1; i < (1 << n); i++)
	{

		int mincnt = 1e9;
		int maxcnt = 0;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				sum += v[j];
				mincnt = min(v[j], mincnt);
				maxcnt = max(v[j], maxcnt);
			}
		}

		if (l <= sum && sum <= r)
		{
			if ((maxcnt - mincnt) >= x)
			{
				ret++;
			}
		}
	}
	cout << ret;
	return 0;
}