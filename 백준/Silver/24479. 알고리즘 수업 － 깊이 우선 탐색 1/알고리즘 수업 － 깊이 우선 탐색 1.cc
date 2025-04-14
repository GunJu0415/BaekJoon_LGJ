#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;

ll n, m, r;
vector<ll> v[100004];
ll visit[100004];
ll cnt = 1;

void dfs(ll x)
{
    visit[x] = cnt++;
    for (ll i : v[x])
    {
        if (visit[i]) continue;
        dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b); 
        v[b].push_back(a);
    }

    for (ll i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    dfs(r);

    for (ll i = 1; i <= n; i++)
    {
        cout << visit[i] << "\n";
    }

    return 0;
}