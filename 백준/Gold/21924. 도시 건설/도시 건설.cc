#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;
ll n,m, sum = 0, maxsum = 0;
vector<pair<ll,pair<ll,ll>>>v;
vector<ll>node[100004];
ll p[100004];
ll visit[100004];
ll findparent(ll x)
{
	if (p[x] != x)
	{
		p[x] = findparent(p[x]);
	}
	return p[x];
}

void dfs(ll x)
{
	//cout << x<<" ";
	visit[x] = 1;
	for (ll i : node[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	//v.resize(n+1, vector<int>(n+1));

	for (ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		node[a].push_back(b);
		node[b].push_back(a);
		v.push_back({ c, {a,b} });
		maxsum += c;
	}
	dfs(1);
	for (ll i = 1; i <= n; i++)
	{
		if (visit[i]==0)
		{
			cout << -1;
			return 0;
		}
	}
	sort(v.begin(), v.end());
	for (ll i = 0; i < m; i++)
	{
		ll Aparent = findparent(v[i].second.first);
		ll Bparent = findparent(v[i].second.second);

		if (Aparent != Bparent)
		{
			//cout << Bparent << " " << Aparent<<" ";
			p[Bparent] = Aparent;
			sum += v[i].first;
		}
	}
	cout << maxsum -sum;
	return 0;
}