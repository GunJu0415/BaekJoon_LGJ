#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;


int n;
int m;
int p1, p2, p3;
int ret = 0;
int ans = 1e9;

int dist[100004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
vector<pair<int, int>>v[100004];



void dijkstra()
{

	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> p1 >> p2 >> p3;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	fill(&dist[0], &dist[100003], 1e9);
	pq.push({ 0, p1 });
	pq.push({ 0, p2 });
	pq.push({ 0, p3 });

	dist[p1] = 0;
	dist[p2] = 0;
	dist[p3] = 0;
	dijkstra();
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 1e9)
		{
			continue;
		}
		if (i == p1 || i == p2 || i == p3)
		{
			continue;
		}

		if (dist[i] > ret) 
		{
			ret = dist[i];
			ans = i;
		}

		else if (dist[i] == ret) 
		{
			ans = min(ans, i);
		}
	}
	cout << ans;
	return 0;
}