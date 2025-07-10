#include<iostream>
#include<algorithm>
using namespace std;

int t;
int main()
{
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << s[0] << s[s.size() - 1] << "\n";

	}

	return 0;
}