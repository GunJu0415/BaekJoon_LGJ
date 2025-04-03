#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

int n;
string ps;
string ps1 = "", ps2 ="";
vector<string>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	cin >> ps;
	int flag =0;
	for (int i = 0; i < ps.size(); i++)
	{
		if (ps[i] == '*')
		{
			flag = 1;
			continue;
		}
		if (!flag)
		{
			ps1 += ps[i];
		}
		else
		{
			ps2 += ps[i];
		}

	}
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}


	for (int i = 0; i < n; i++)
	{
		int k = ps2.size()-1;
		int aa = 0, bb = 0;
		if (ps1.size() + ps2.size() > v[i].size())
		{
			v[i] = "NE";
			continue;
		}
		for (int j = 0; j < ps1.size(); j++)
		{
			if (v[i][j] != ps1[j])
			{
				aa = 1;
				break;
			}
			v[i][j] = ' ';
			//cout << v[i] << " ";
		}
		//cout << "\n";
		if (aa == 0)
		{
			for (int j = v[i].size()-1;j>=v[i].size()-ps2.size();j--)
			{
				//cout << v[i][j] << " " << ps2[k];
				if (v[i][j] != ps2[k])
				{
					//cout << "asdfadf";
					bb = 1;
					break;
				}
				//v[i][j] = ' ';
				//cout << v[i];
				k--;
			}

		}
		//cout << aa << bb << "\n";
		if (aa == 1 || bb == 1)
		{
			v[i] = "NE";
		}
		else
		{
			v[i] = "DA";
		}
	}

	for (auto i : v)
	{
		cout << i << "\n";
	}
	return 0;
}