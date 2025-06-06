#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using  namespace std;


int n, m, A, B, C;
vector<pair<int, int>>v[14];
int dist[14];
int p[14];
int ret = 1e9;


bool visit[14];
void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < cost)
		{
			continue;
		}
		for (auto i : v[node])
		{
			int nextnode = i.first;
			int nextcost = i.second + cost;
			if (dist[nextnode] > nextcost)
			{
				p[nextnode] = node;
				dist[nextnode] = nextcost;
				pq.push({ nextcost, nextnode });
			}
		}
	}
}

void dfs(int x, int sum, int cnt)
{
	//cout << x << " ";
	if (x == B)
	{
		if (sum <= C)
		{
			ret = min(cnt, ret);
		}
	}
	visit[x] = 1;
	for (auto i : v[x])
	{
		if (visit[i.first])
		{
			continue;
		}
		dfs(i.first, sum + i.second, cnt = max(cnt, i.second));
		visit[i.first] = 0;
	}
}
void findParent(int x)
{
	if (p[x] == 0)
	{
		return;
	}
	for (auto i : v[x])
	{
		if (i.first == p[x])
		{
			ret = max(i.second, ret);
		}
	}
	findParent(p[x]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> A >> B >> C;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	dfs(A, 0, 0);
	fill(dist, dist + n+1, 1e9);
	//dijkstra(A);
	//if (dist[B] > C)
	//{
	//	cout << -1;
	//	return 0;
	//}
	//findParent(B);
	if (ret == 1e9)
	{
		cout << -1;
		return 0;
	}
	cout << ret;
	return 0;
}