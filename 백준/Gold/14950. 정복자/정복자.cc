#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n, m, t;
int sum = 0;

int p[10004];
vector<pair<int, pair<int, int>>>v;


int findParent(int x)
{
	if (x != p[x])
	{
		p[x] = findParent(p[x]);
	}
	return p[x];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> t;
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

	int temp = 0;
	for (int i = 0; i < m; i++)
	{
		int Aparent = findParent(v[i].second.first);
		int Bparent = findParent(v[i].second.second);
		if (Aparent != Bparent)
		{
			p[Bparent] = Aparent;
			sum += v[i].first + temp;
			temp += t;
		}
	}
	
	cout << sum;
	return 0;
}