#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int l;
int n;
int ret = 0;
vector<int>v;
vector<int>tp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int temp = l;
	for (int i = 0; i < n; i++)
	{

		if (!tp.empty())
		{
			if (temp>=abs(tp[tp.size() - 1] - v[i]))
			{
				temp -= abs(tp[tp.size() - 1] - v[i]);
				tp.push_back(v[i]);
			}
			else
			{
				tp.clear();
				ret++;
				temp = l-1;
				tp.push_back(v[i]);
			}
		}
		else
		{
			ret++;
			temp = l - 1;
			tp.push_back(v[i]);
		}

		//if (!tp.empty() && i == n - 1)
		//{
		//	ret++;
		//}
	}
	cout << ret;
	return 0;
}