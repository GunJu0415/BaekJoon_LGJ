#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

typedef long long int ll;

ll n, m;
ll cnt[1000004];
ll sum = 0;
ll ans = 0;
int main()
{
	cin >> n >> m;

	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		sum += a;
		cnt[sum % m]++;

	}
	for (int i = 0; i < n; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << cnt[0]+ans;
	return 0;
}