#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m,start;

vector<pair<int, int>>v[300004];
int dist[20004];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost)
		{
			continue;
		}
		for (auto i : v[now])
		{
			int nextNode = i.first;
			int nextCost = i.second + cost;

			if (dist[nextNode] > nextCost)
			{
				dist[nextNode] = nextCost;
				pq.push({ nextCost, nextNode });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}
	fill(dist, dist + n + 1, 1e9);
	dijkstra(start);
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 1e9)
		{
			cout << "INF" << "\n";
		}
		else
		{
			cout << dist[i] << "\n";
		}
	}
	return 0;
}