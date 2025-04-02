#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>


using namespace std;


int n, m, s, t;
int dist[50004];
vector<pair<int, int>>v[5004];

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
				dist[nextnode] = nextcost;
				pq.push({ nextcost, nextnode });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	fill(&dist[0], &dist[n + 1], 1e9);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	cin >> s >> t;
	dijkstra(s);
	cout << dist[t];
	return 0;
}