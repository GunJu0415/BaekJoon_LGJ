#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
ll n;
vector < ll >v;
int num1, num2;



void bs()
{
	ll start = 0;
	ll end = n-1;
	ll sum = 1e9*3;

	while (start < end)
	{
		ll temp = v[start] + v[end];

		if (abs(temp) > sum)
		{
			if (temp < 0)
			{
				start++;
			}
			else if(temp > 0)
			{
				end--;
			}
			else
			{
				num1 = v[start];
				num2 = v[end];
				return;
			}
		}
		else
		{

			sum = abs(temp);
			num1 = v[start];
			num2 = v[end];
			if (temp < 0)
			{
				start++;
				
			}
			else if (temp > 0)
			{
				end--;
				
			}
			else
			{
				return;
			}
			
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());
	bs();
	cout << num1 << " " << num2;
	return 0;
}