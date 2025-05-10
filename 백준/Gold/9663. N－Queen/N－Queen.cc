#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n,ret = 0;
int low[20];



bool check(int y, int x)
{
	for (int i = 0; i < y; i++)
	{
		if (low[i] == x)
		{
			return 0;
		}
		if (abs(y - i) == abs(low[i] - x))
		{
			return 0;
		}
	}
	return 1;
}

void go(int y)
{
	if (y == n)
	{
		ret++;
		return;
	}


	for (int x = 0; x < n; x++)
	{
		if (check(y, x))
		{
			low[y] = x;
			go(y + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	go(0);
	cout << ret;
	return 0;
}