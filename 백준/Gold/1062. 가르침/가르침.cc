#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int n, k, ans= 0, sum = 0;


vector<int>v;


void word(int abc)
{
	sum = 0;
	for (int i = 0; i < n; i++)
	{
		if ((v[i] & abc) == v[i])
		{
			sum++;
		}
	}

}

void go(int abc, int step, int cnt)
{
	if (cnt == k)
	{
		word(abc);
		ans = max(sum, ans);
		return;
	}
	if (step == 26)
	{
		return;
	}
	int temp =abc;
	temp |= 1 << step;
	go(temp, step+1,cnt+1);
	go(abc, step + 1,cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int mask = 0;
		for (char c : s)
		{
			mask |= 1 << (c - 'a');
		}
		v[i] = mask;
	}

	go(0, 0, 0);
	cout << ans;
	return 0;
}