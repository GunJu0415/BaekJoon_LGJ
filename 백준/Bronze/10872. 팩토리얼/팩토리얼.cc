#include<iostream>
using namespace std;

int n;
int ret = 1;
int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	cout << ret;
	return 0;
}