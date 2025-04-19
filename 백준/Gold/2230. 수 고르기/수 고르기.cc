#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

typedef long long int ll;
ll n, m;
vector<ll>v;
priority_queue<ll, vector<ll>, greater<ll>>pq;


void tp()
{
	ll left = 0;
	ll right = 1;
	ll  sum = 0;
	while (right < n && left < right)
	{
		sum = v[right] - v[left];
		if (sum < m)
		{
			right++;
		}
		else
		{
			if (left + 1 == right)
			{
				right++;
			}
			left++;
			//cout << sum << " ";
			pq.push(sum);
			//ans = min(ans, sum);
		}

	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (ll i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	tp();
	cout << pq.top();
	return 0;
}