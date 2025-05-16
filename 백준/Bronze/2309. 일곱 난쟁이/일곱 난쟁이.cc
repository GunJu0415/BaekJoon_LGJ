#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>v;
vector<int>temp;

void go(int here, int sum)
{
	if (temp.size() == 7)
	{
		if (sum == 100)
		{
			sort(temp.begin(), temp.end());
			for (int i : temp)
			{
				cout << i << "\n";

			}
			exit(0);
			return;
		}
	}
	if (here == 9)
	{
		return;
	}

	for (int i = here; i < 9; i++)
	{
		temp.push_back(v[i]);
		go(i + 1, sum  + v[i]);
		temp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	go(0, 0);
	return 0;
}