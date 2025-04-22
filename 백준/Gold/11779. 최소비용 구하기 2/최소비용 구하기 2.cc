#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int n, m, st, ed;


vector<pair<int, int>> v[1004];
int dist[1004];
int p[1004];


void parent(int x,int cnt)
{
	if (x == st)
	{
		cout << cnt<< "\n";
		cout << x << " ";
		return;
	}
	parent(p[x], cnt+1);
	cout << x << " ";
}

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, start });
	dist[start] = 0;
	p[start] = 0;

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
			int nextcost = i.second + cost;
			int nextnode = i.first;
			if (dist[nextnode] > nextcost)
			{
				dist[nextnode] = nextcost;
				p[nextnode] = node;
				pq.push({ nextcost, nextnode });
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	fill(&dist[0], &dist[n + 1], 1e9);
	cin >> st >> ed;
	dijkstra(st);
	cout << dist[ed] << "\n";
	parent(ed, 1);
	return 0;
}