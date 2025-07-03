#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
ll n;
vector<ll>v;
vector<ll>v2;

ll ret;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int zero = 0;
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		if (a > 1)
		{
			v.push_back(a);
		}
		else if( a< 0)
		{
			v2.push_back(a);
		}
		else if(a == 1)
		{
			ret++;
		}
		else
		{
			zero++;
		}
	}

	sort(v.begin(), v.end(), greater<>());
	sort(v2.begin(), v2.end());

	for (ll i = 1; i < v.size(); i += 2)
	{
		ret += (v[i] * v[i - 1]);
	}
	if (v.size() % 2 != 0 && !v.empty())
	{
		ret += v[v.size() - 1];
	}
	//cout << ret << " ";


	for (ll i = 1; i < v2.size(); i += 2)
	{
		//cout << v2[i] << " " << v2[i - 1] << "\n";
		ret += v2[i] * v2[i - 1];
	}
	//cout << ret << " ";
	if (v2.size() % 2 != 0 && !v2.empty())
	{
		if (zero)
		{
			ret += v2[v2.size() - 1] * 0;
		}
		else
		{
			ret += v2[v2.size() - 1];
		}
		
	}
	cout << ret;

	return 0;
}


