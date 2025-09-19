#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;




typedef long long ll;

ll k, n;
ll ret = 0;
vector<ll>v;



void bs()
{
	ll start = 1;
	ll end = v[v.size() - 1];
	ll sum = 0;

	while (start <= end)
	{
		sum = 0;
		ll mid = (start + end) / 2;
		for (ll i = 0; i < k; i++)
		{
			sum += v[i] / mid;
		}

		//cout << mid << " ";
		//cout << sum << " ";

		if (sum < n)
		{
			 end = mid - 1;
		}
		else// if (sum > n)
		{
			start = mid + 1;
			ret = max(mid, ret);
		}

	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;

	for (ll i= 0; i < k; i++)
	{
		ll a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	//if (v.size() == n)
	//{
	//	cout << v[0];
	//	return 0;
	//}
	bs();
	cout << ret;

	return 0;
}