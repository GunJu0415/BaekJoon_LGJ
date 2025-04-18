#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int n, k;
vector<int>v;
int dist[100004];
int p[100004];
void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, start });
	p[start] = 0;
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i : {node + 1, node - 1, 2 * node})
		{
			int nextnode = i;
			if (i > 100000 || i < 0)
			{
				continue;
			}
			int nextcost = cost + 1;

			if (dist[nextnode] > nextcost)
			{
				p[nextnode] = node;
				dist[nextnode] = nextcost;
				pq.push({ nextcost, nextnode });
			}
		}
	}
}

void findP(int x)
{
	if (x == n)
	{
		cout << x<< " ";
		return;
		
	}
	findP(p[x]);
	cout << x<< " ";

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	fill(&dist[0], &dist[100004], 1e9);
	dijkstra(n);
	cout << dist[k]<< "\n";
	findP(k);
	return 0;
}