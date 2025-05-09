#include<iostream>

using namespace std;

int n;
int cnt = -1;
int mn = 1234897;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i * 5 + j * 3 == n && mn > i+j )
			{
				mn = i + j;
				cnt = i + j;
			}
		}
	}
	cout << cnt;
	return 0;
}