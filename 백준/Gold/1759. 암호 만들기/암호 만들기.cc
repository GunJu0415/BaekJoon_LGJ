#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int l, c, mcnt = 0, jcnt = 0;
vector<char>v, temp;

void go(int here)
{
	if (temp.size() == l)
	{
		mcnt = 0;
		jcnt = 0;
		for (int i : temp)
		{
			if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u')
			{
				mcnt++;
			}
			else
			{
				jcnt++;
			}
			//cout << v[i];
		}

		if (mcnt >= 1 && jcnt > 1)
		{
			for (int i : temp)
			{
				cout << v[i];
			}
			cout << "\n";
		}
		
		return;
	}
	for (int i = here; i < c; i++)
	{
		temp.push_back(i);
		go(i + 1);
		temp.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	go(0);
	return 0;
}