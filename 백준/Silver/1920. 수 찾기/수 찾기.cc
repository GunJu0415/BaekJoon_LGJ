#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int>v1, v2 ;


int bs(int num)
{
	int start = 0;
	int end = n-1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (v1[mid] < num)
		{
			start = mid + 1;
		}
		else if(v1[mid] > num)
		{
			end = mid - 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v1.push_back(a);
	}
	cin >> m;
	sort(v1.begin(), v1.end());
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		v2.push_back(a);
	}

	for (int i : v2)
	{
		cout << bs(i)<<"\n";
	}

	return 0;
}