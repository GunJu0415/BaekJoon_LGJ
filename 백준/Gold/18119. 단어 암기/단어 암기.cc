#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int n, m;
int word[10004];
int mask =0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;


	mask = (1 << 26) - 1;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int temp = 0;
		for (int j = 0; j < s.size(); j++)
		{
			temp |= 1 << (s[j] - 'a');
		}
		word[i] = temp;
	}

	for (int i = 0; i < m; i++)
	{
		int a,cnt = 0;
		char c;
		cin >> a >> c;
		if (a == 1)
		{
			mask ^= 1 << (c - 'a');
		}
		else
		{
			mask |= 1 << (c - 'a');
		}
		for (int j = 0; j < n; j++)
		{
			if ((word[j] & mask) == word[j])
			{
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}