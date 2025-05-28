#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef long long int ll;

ll dist[5][5004];
ll parent[5004];
ll n, m, p;
bool flag = 0;

vector<pair<ll, ll>>v[5004];


void dijkstra(ll num, ll start)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > pq;
	pq.push({ 0, start });
	dist[num][start] = 0;

	while (!pq.empty())
	{
		ll node = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();

		if (dist[num][node] < cost)
		{
			continue;
		}

		for (auto i : v[node])
		{
			ll nextnode = i.first;
			ll nextcost = i.second + cost;

			if (dist[num][nextnode] >= nextcost)
			{
				//if (nextnode == p)
				//{
				//	flag = 1;
				//}
				//parent[nextnode] = node;
				dist[num][nextnode] = nextcost;
				pq.push({ nextcost, nextnode });
			}
		}
	}
}


void findParent(int x)
{
	if (x == p)
	{
		flag = 1;
	}
	if (parent[x] == x)
	{
		//cout << x << " ";
		return;
	}

	findParent(parent[x]);
	//cout << x << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (ll i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	
	cin >> n >> m >> p;
	


	for (ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	
	fill(&dist[0][0], &dist[4][n + 1], 1e9);
	dijkstra(0,1);
	dijkstra(1,p);
	int ret = 0;

	ret =  dist[1][1] + dist[1][n];

	
	if (ret == dist[0][n])
	{
		cout << "SAVE HIM";
	}
	else
	{
		cout << "GOOD BYE";
	}

	return 0;
}