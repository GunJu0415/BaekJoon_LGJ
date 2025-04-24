#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int k, n, m;
vector<int> v[20004];
int p[20004];
int visit[20004];
bool flag = 0;
int FindParent(int x)
{
	if (p[x] != x)
	{
		p[x] = FindParent(p[x]);
	}
	return p[x];
}
void dfs(int x, int cnt)
{
	//cout << x << " " << cnt << "\n";
	visit[x] = cnt;
	if (cnt == 0)
	{
		cnt = 1;
	}
	else
	{
		cnt = 0;
	}
	for (int i : v[x])
	{
		if (visit[i] != -1)
		{
			if (visit[i] != cnt)
			{
				flag = 1;
				return;
			}
			continue;
		}
		dfs(i, cnt);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	while (k--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			v[i].clear();
		}
		flag = 0;
		fill(&visit[0], &visit[n + 1], -1);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == -1)
			{
				dfs(i, 0);
			}
			if (flag)
			{
				break;
			}
		}
		if (flag)
		{
			cout << "NO" << "\n";
		}
		else
		{
			cout << "YES" << "\n";
		}
	}
	return 0;
}