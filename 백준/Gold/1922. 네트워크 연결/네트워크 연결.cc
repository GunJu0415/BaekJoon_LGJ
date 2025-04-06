#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int  n, m;
int sum =0;
int p[1004];
vector<pair<int, pair<int, int>>>v;

int findparent(int x)
{
	if (p[x] != x)
	{
		p[x] = findparent(p[x]);
	}
	return p[x];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c,{a, b} });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		int Aparent = findparent(v[i].second.first);
		int Bparent = findparent(v[i].second.second);

		if (Aparent != Bparent)
		{
			p[Bparent] = Aparent;

			sum += v[i].first;
		}

	}

	cout << sum;
	return 0;
}