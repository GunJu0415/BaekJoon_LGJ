#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long int ll;
ll n, m;
queue<ll>clip;
vector<pair<ll, ll>>v[100004];
ll dist[100004];
ll en[100004];


void dijkstra()
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    pq.push({ 0, 0 });
    dist[0] = 0;
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if (dist[node] < cost)
        {
            continue;
        }
        for (auto i : v[node])
        {
            ll nextnode = i.first;
            ll nextcost = i.second + cost;
            if (nextnode != n - 1 && en[nextnode] == 1)
            {
                continue;
            }
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
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        cin >> en[i];
    }
    
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }

    fill(&dist[0], &dist[100004], 1e18);
    dijkstra();

    if (dist[n - 1] == 1e18)
    {
        cout << -1;
    }
    else
    {
        cout << dist[n - 1];
    }

    return 0;
}