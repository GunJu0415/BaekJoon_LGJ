#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef long long int ll;

map<char, ll>dice;
ll n;
vector<string>f3;
vector<string>f2;
ll min3 = 1e9;
ll min2 = 1e9;
ll min1 = 1e9;
ll max1 = 0;
ll sum = 0;
//string min3;
//string min2;

ll ret = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (char i = 'a'; i <= 'f'; i++)
	{
		cin >> dice[i];
		sum += dice[i];
		min1 = min(dice[i], min1);
		max1 = max(dice[i], max1);
	}

	// 3개씩
	f3.push_back("abc");
	f3.push_back("ace");
	f3.push_back("ade");
	f3.push_back("abd");

	f3.push_back("fbc");
	f3.push_back("fce");
	f3.push_back("fde");
	f3.push_back("fbd");


	// 2개씩 한거
	f2.push_back("ab");
	f2.push_back("ac");
	f2.push_back("ad");
	f2.push_back("ae");

	f2.push_back("fb");
	f2.push_back("fc");
	f2.push_back("fd");

	f2.push_back("fe");
	f2.push_back("bc");
	f2.push_back("ce");

	f2.push_back("ed");

	f2.push_back("bd");


	for (ll i = 0; i < f3.size(); i++)
	{ 
		min3 = min(dice[f3[i][0]] + dice[f3[i][1]] + dice[f3[i][2]], min3);
	}

	for (ll i = 0; i < f2.size(); i++)
	{
		min2 = min(dice[f2[i][0]] + dice[f2[i][1]], min2);
	}

	//cout << min3 << Q" " << min2 << " " << min1 << "\n";

	if (n > 1)
	{
		ret += min3 * 4;
		ret += (((n - 1) * 4L) + ((n - 2) * 4)) *min2;
		ret += ((n - 2) * (n - 2) + 4 * (n - 2) * (n - 1))* min1;

		//(((n - 2) * 4) * (n - 1)) + ((n * n) - (n + n - 1 + n - 1 + n - 2)) * min1;		//ret += 4
	}
	else
	{
		ret = sum - max1;
	}
	cout << ret;
	return 0;
}