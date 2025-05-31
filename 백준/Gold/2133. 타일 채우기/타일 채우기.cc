#include<iostream>
#include<vector>

using namespace std;

int n;
int p[31];


void dp()
{
	p[0] = 0;
	p[1] = 0;
	p[2] = 3;
	p[3] = 0;
	p[4] = 11;
	for (int i = 5; i <= n; i++)
	{
		if (i % 2 != 0)
		{
			p[i] = 0;
		}
		else
		{
			p[i] = (p[i - 2] * 4) - p[i - 4];
		}
	}
}
int main()
{
	cin >> n;
	dp();
	cout << p[n];
	return 0;
}