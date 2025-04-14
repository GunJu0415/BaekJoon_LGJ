#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n, ans, dn, start;

vector<int>v[104];
int visit[104];
void delNode(int x)
{
	//cout << x << "\n";

	for (int i : v[x])
	{
		if (i == dn)
		{
			v[x].erase(remove(v[x].begin(), v[x].end(), dn), v[x].end());
		}
		delNode(i);
	}
}

void dfs(int x)
{
	//cout << x << "\n";
	visit[x]++;
	if (v[x].empty())
	{
		ans++;
	}
	for (int i : v[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;	
		cin >> a;
		if (a == -1)
		{
			v[0].push_back(i);
			start = i;
		}
		a++;
		v[a].push_back(i);
	}
	cin >> dn;
	dn++;
	if (dn == start)
	{
		cout << 0;
		return 0;
	}

	delNode(0);
	dfs(0);

	cout << ans;
	return 0;
}