#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

string s, t;
int ans = 0;
void go(string ss)
{
	//cout << ss << "\n";
	if (ss == s)
	{
		ans = 1;
		return;
	}

	if (ss.size() < s.size())
	{
		return;
	}

	if (ss[ss.size() - 1] == 'A')
	{
		string temp = ss;
		temp.pop_back();
		go(temp);
	}
	if (ss[0] == 'B')
	{
		string temp = ss;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		go(temp);
	}

}
int main()
{
	cin >> s >> t;
	go(t);
	cout << ans;
	return 0;
}
