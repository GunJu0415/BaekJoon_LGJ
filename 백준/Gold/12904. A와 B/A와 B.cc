#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s, t;
bool flag;

void go(string tt)
{
	//cout << tt << "\n";
	if (tt.size() == s.size())
	{
		if (tt == s)
		{
			flag = 1;
		}
		return;
	}
	if (tt[tt.size() - 1] == 'B')
	{
		string temp = tt;
		temp.pop_back();
		reverse(temp.begin(), temp.end());
		go(temp);
	}
	else if (tt[tt.size() - 1] == 'A')
	{
		string temp = tt;
		temp.pop_back();
		go(temp);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	cin >> t;

	go(t);
	cout << flag;
	return 0;
}