#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


int t;
int n, d, c;


vector<pair<int, int>>v[10004];
int dist[10004];
set<int>nn;
int cnt = 0, ans = 0;

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
			int nextcost = i.second + cost;
			int nextnode = i.first;

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

	cin >> t;
	while (t--)
	{
		//nn.clear();
		cnt = 0;
		ans = 0;
		cin >> n>> d>> c;
		for (int i = 0; i < d; i++)
		{
			int a, b, f;
			cin >> a >> b >> f;
			nn.insert(a);
			nn.insert(b);
			//v[a].push_back({ b, f });
			v[b].push_back({ a, f });
		}
		fill(&dist[0], &dist[n + 1], 1e9);
		dijkstra(c);
		for (int i =1;i<=n;i++)
		{
			v[i].clear();
			if (dist[i] != 1e9)
			{
				
				//cout << dist[i] <<"\n";
				cnt++;
				ans = max(ans, dist[i]);
			}
		}
		cout << cnt << " " << ans <<"\n";
	}
	return 0;
}

