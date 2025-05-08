#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int n, m, r;
vector<int>v[100004];
int visit[100004];



void dfs(int x, int cnt)
{
	visit[x] = cnt;
	for (int i : v[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i, cnt + 1);
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
		sort(v[i].begin(), v[i].end(), greater<>());
	}
	dfs(r, 1);
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0 && i > 1)
		{
			cout << -1 << "\n";
			continue;
		}
		cout << visit[i]-1 <<"\n";
	}
}