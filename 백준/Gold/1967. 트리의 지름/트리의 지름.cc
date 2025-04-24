#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, ans = 0, start, scnt = 0;

vector<pair<int, int>>v[10004];
int dist[10004];
bool visit[10004];

void print()
{
	cout << "\n";
	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << " ";
	}
	cout << "\n";
}
void dfs(int x, int cnt)
{
	visit[x] = 1;
	if (cnt > scnt)
	{
		scnt = cnt;
		start = x;
	}
	for (auto i : v[x])
	{
		if (visit[i.first])
		{
			continue;
		}
		dfs(i.first, cnt + i.second);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	dfs(1, 0);
	scnt = 0;
	fill(&visit[0], &visit[n + 1], 0);
	dfs(start, 0);
	cout << scnt;
	//cout << ans;
	return 0;
}