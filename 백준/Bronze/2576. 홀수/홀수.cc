#include<iostream>
#include<algorithm>
using namespace std;

int n = 1e9;
int ret = 0;
int main()
{

	for (int i = 0; i < 7; i++)
	{
		int a;
		cin >> a;
		if (a % 2 != 0)
		{
			ret += a;
			n = min(n, a);
		}
	}
	if (ret == 0)

	{
		cout << -1;
		return 0;
	}
	cout << ret <<"\n";
	cout << n;
	return 0;
}