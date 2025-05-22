#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<int>v;
int p[10004];
void dp()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = v[i]; j <= k; j++)
		{
			if (j == v[i])
			{
				p[j] += 1;
			}
			else
			{
				p[j] += p[j - v[i]];
			}

		}
	}
}
int main()
{
	cin >> n >> k;
	if (n <= 0 || n>100)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a > 100000)
		{
			return 0;
		}
		v.push_back(a);
	}	

	dp();



	cout << p[k];

	return 0;
}