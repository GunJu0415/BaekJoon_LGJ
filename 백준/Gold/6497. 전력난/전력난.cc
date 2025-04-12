#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;
ll n, m,sum =0;
vector<ll>ans;

ll p[200004];


ll findparent(ll x)
{
	if (p[x] != x)
	{
		p[x] = findparent(p[x]);
	}
	return  p[x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		sum = 0;
		cin >> n >> m;
		vector<pair<ll, pair<ll, ll>>>v;
		if (n == 0 && m == 0)
		{
			break;
		}
		for (ll i = 0; i < n; i++)
		{
			p[i] = i;
		}	
		for (ll i = 0; i < m; i++)
		{
			ll a, b, c;
			cin >> a >> b >> c;
			v.push_back({ c,{ a, b } });
		}	
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			ll Aparent = findparent(v[i].second.first);
			ll Bparent = findparent(v[i].second.second);
			if (Aparent != Bparent)
			{
				p[Bparent] = Aparent;
			}
			else
			{
				sum += v[i].first;
			}

		}
		ans.push_back(sum);
	}

	for (ll i : ans)
	{
		cout << i << "\n";
	}




	return 0;
}