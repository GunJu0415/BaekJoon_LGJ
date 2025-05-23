#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;


int n;

int dp[1004];
int p[1004];
int ret = 0;
int st = 0;
vector<int>v;


void parent(int x)
{
	if (p[x] == x)
	{
		cout << v[x] << " ";
		return;
	}

	parent(p[x]);

	cout << v[x] <<" ";
}

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
		dp[i] = 1;
		p[i] = i;
		for (int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
			{
				if (dp[i] < dp[j] + 1)
				{
					p[i] = j;
				}
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (ret < dp[i])
		{
			st =i;
		}
		ret = max(ret, dp[i]);
	}

	cout << ret <<"\n";
	parent(st);

	return 0;
}