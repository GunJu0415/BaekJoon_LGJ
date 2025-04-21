#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<long long int>v;
long long int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (long long int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (long long int i = 0; i < n; i++)
	{
		cout << v[i] << '\n';
	}
	return 0;
}