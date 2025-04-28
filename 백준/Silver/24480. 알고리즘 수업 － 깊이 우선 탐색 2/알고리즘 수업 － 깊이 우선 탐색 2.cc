#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, r, cnt=1;
vector<int>v[100005];
int visit[100005];
void dfs(int x)
{
	visit[x] = cnt;
	cnt++;
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
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end(),greater<>());
	}
	dfs(r);

	for (int i = 1; i <= n; i++)
	{
		cout << visit[i] << "\n";
	}
	return 0;
}