#include<iostream>

using namespace std;


int x, n;
int ret = 0;
int main()
{
	cin >> x >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		ret += a * b;
	}
	if (ret == x)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}