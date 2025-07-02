#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>

using namespace std;


int t;
int n;
vector<string>v;

int longest = 0, lidx, shortest;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	cin >> t;


	while (t--)
	{
		cin >> n;
		int flag = 0;
		v.clear();
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			if (s.size() > longest)
			{
				longest = s.size();
				lidx = i;
			}
			v.push_back(s);
		}

		sort(v.begin(), v.end());
		for (int i = 0; i < n - 1; i++)
		{
			if (v[i + 1].compare(0, v[i].size(), v[i]))
			{

			}
			else
			{
				flag = 1;
				break;
			}

		}

		if (flag)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}


	}
	return 0;
}