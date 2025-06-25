#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int n;
int ret = 1e9;
vector<int>v;
int ans = 1e9;
int p[200004];
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

	sort(v.begin(), v.end());
	if (n == 1)
	{
		ans = v[0];

	}
	else
	{
		if (n % 2 == 0)
		{
			ans = v[(v.size() / 2) - 1];
		}
		else
		{
			ans = v[(v.size() / 2)];
		}
		
	}


	cout << ans;
	return 0;
}