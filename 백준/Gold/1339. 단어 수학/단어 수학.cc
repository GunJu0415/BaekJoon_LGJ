#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
using namespace std;

int n;
vector<string>v;
map<char, int>mp;
vector<pair<int, char>>pv;

int cnt[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			mp[v[i][j]] += pow(10, v[i].size() - j);
			//cout << cnt[v[i][j]] << " ";
		}
	}
	for (auto i : mp)
	{
		pv.push_back({ i.second, i.first });
	}
	sort(pv.begin(), pv.end(), greater<>());
	int cnt = 9;
	for (int i =0;i<pv.size();i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				if (v[j][k] == pv[i].second)
				{
					v[j][k] = cnt + '0';
				}
			}
		}
		cnt--;
	}
	int ans = 0;
	for (int i =0; i<v.size();i++)
	{
		ans += stoi(v[i]);
	}
	cout << ans;
	return 0;
}