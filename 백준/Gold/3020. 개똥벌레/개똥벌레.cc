#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, h;



int up[500004];
int down[500004];
int cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> h;

	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;

		if (i % 2 != 0)
		{
			up[a]++;
		}
		else
		{
			down[h - a + 1]++;
		}
	}

	for (int i = 2; i <= h; i++)
	{
		up[h+1-i] += up[h - i +2];
		down[i] += down[i - 1];
	}
	int temp =  1e9;
	for (int i = 1; i <= h; i++)
	{
		//cout << up[i] + down[i] << "\n";
		if (temp > up[i] + down[i])
		{
			//cout << up[i] + down[i] << "\n";
			temp = up[i] + down[i];
			cnt = 0;
		}

		if (temp == up[i] + down[i])
		{
			cnt++;
		}

	}
	cout << temp << " " << cnt;

	return 0;
}