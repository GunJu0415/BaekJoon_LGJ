#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<pair<int, pair<int, int>>>v;
int p[10004];

int n, m;
int sum = 0;

int findParent(int v)
{
	if (p[v] != v)
	{
		p[v] = findParent(p[v]);
	}

	return p[v];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		int Aparent = findParent(v[i].second.first);
		int Bparent = findParent(v[i].second.second);

		if (Aparent != Bparent)
		{
			p[Bparent] = Aparent;

			sum += v[i].first;
		}
		
	}
	cout << sum;
	return 0;
}