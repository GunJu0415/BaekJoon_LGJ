#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int  p[304];

int n;

void dp()
{
	p[0] = v[0];
	p[1] = v[1];
	p[2] = p[1] + v[2];
	p[3] = max(v[2] + v[3], v[1] + v[3]);
	for (int i = 4; i <= n; i++)
	{
		int a = p[i - 2] + v[i];
		int b = p[i - 3] + v[i] + v[i -1];
		p[i] = max(a, b);
	}
}
int main()
{
	cin >> n;

	v.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	dp();
	cout << p[n];
	return 0;
}