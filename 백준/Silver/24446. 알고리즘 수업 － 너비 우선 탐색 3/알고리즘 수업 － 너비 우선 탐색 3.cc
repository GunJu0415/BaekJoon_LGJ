#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;



int n, m, r;
vector<int>v[100004];
int dist[100004];

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i : v[x])
		{
			if (dist[i] != 1e9)
			{
				continue;
			}
			dist[i] = dist[x] + 1;
			q.push(i);
		}
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
	fill(&dist[0], &dist[n + 1], 1e9);
	bfs(r);
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 1e9)
		{
			cout << -1 << "\n";
			continue;
		}
		cout << dist[i]<<"\n";
	}
}