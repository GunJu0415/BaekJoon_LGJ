#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
using namespace std;

int t;
string p;
vector<int>v;
int n, temp = 0;;
string s;

void print()
{
	cout << "\n";
	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}


void Rev()
{
	reverse(v.begin(), v.end());
}

void Drop()
{

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--)
	{
		bool flag = 1;
		v.clear();
		p.clear();
		cin >> p;
		cin >> n;
		//while (1)
		//{
		//	char a;
		//	cin >> a;
		//	if (a != 'R' && a != 'D')
		//	{
		//		n = a - '0';
		//		break;
		//	}
		//	p.push_back(a);
		//}

		//cout << "asdfsdfsadfsd";
		while (1)
		{
			char a;
			cin >> a;
			if (a >= '0' && a <= '9')
			{
				s.push_back(a);
			}
			else if (a == ',')
			{
				if (s.empty())
				{
					continue;
				}
				v.push_back(stoi(s));
				s.clear();
			}
			else if (a == ']')
			{
				if (s.empty())
				{
					break;
				}
				v.push_back(stoi(s));
				s.clear();
				break;
			}
		}

		int re  = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				re ^= 1;
			}
			else if (p[i] == 'D')
			{
				if (v.empty())
				{
					flag = 0;
					cout << "error\n";
					break;
				}
				if (!re)
				{
					v.erase(v.begin());
				}
				else
				{
					v.pop_back();
				}
				
			}
		}


		if (flag)
		{
			cout << '[';
			if (v.empty())
			{

			}
			else
			{
				if (re)
				{
					reverse(v.begin(), v.end());
				}
				for (int i = 0; i < v.size() - 1; i++)
				{
					cout << v[i] << ",";
				}
				cout << v[v.size() - 1];
			}

			cout << "]\n";
		}
	}


	return 0;
}