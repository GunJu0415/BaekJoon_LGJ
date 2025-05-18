#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;


int n;
int ret = 0;

void go(int here)
{
	if (here > n)
	{
		return;
	}
	
	string s = to_string(here);
	bool flag = 1;
	if (s.size() > 2)
	{
		int temp = s[0] - s[1];
		for (int i = 2; i < s.size(); i++)
		{
			if (temp == s[i - 1] - s[i])
			{
			
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}
	if (flag)
	{
		//cout << here << " ";
		ret++;
	}
	go(here + 1);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	go(1);
	cout << ret;
	return 0;
}