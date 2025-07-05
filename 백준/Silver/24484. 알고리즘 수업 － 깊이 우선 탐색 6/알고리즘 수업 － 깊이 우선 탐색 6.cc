#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long int ll;
ll n, m, r;
ll cnt = 1;
ll ret = 0;
vector<ll>v[100004];
ll visit[100004];
ll depth[100004];
void dfs(ll x, ll num)
{
	depth[x] = num;
	visit[x] = cnt++;
	for (ll i : v[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i, num+1);
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
		sort(v[i].begin(), v[i].end(), greater<>());
	}
	//memset(visit, -1, sizeof(visit));
	memset(depth, -1, sizeof(depth));
	dfs(r, 0);

	for (ll i = 1; i <= n; i++)
	{
		//cout << depth[i] << " ";
		ret += visit[i] * depth[i];
	}
	cout << ret;
	return 0;
}