#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;



set<string>st;
int cnt;
string s;
vector<char>v;
void go(int here, int num)
{
	if (v.size() == num)
	{
		for (char i : v)
		{
			cout << i;
		}
		puts("");
		cnt++;
	}
	for (int i = here; i < s.size(); i++)
	{
		v.push_back(s[i]);
		go(i + 1, num);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	//for (int i = 1; i <= s.size(); i++)
	//{
	//	v.clear();
	//	go(0, i);
	//}
	//go(0);
	for (int i = 0; i < s.size(); i++)
	{
		string temp = s;
		if (i > 0)
		{
			for (int k = 0; k < i; k++)
			{
				temp.erase(temp.begin());
			}

		}
		//st.insert(temp);
		for (int j = s.size() -1; j >= i; j--)
		{
			//cout << temp << "\n";
			st.insert(temp);
			temp.pop_back();
			
		}
	}
	//for (auto aa: st)
	//{
	//	cout << aa << "\n";
	//}
	cout << st.size();
	//cout << cnt;
	return 0;
}