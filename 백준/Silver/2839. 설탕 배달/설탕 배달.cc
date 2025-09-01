#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int n;
int sum = 0;
int cnt = 0;
int ret =  1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n < 5)
	{
		if (n % 3 == 0)
		{
			cnt = 1;
			cout << cnt;
			return 0;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i * 5 <= n; i ++)
	{
		
		cnt = i;
		sum = 5 * i;
		//cout << sum << " ";
		for (int j = 0; j * 3 + sum <=  n; j ++)
		{
			//cnt;
			int temp = sum;
			temp += j * 3;

			if (temp == n)
			{
				ret = min(cnt + j, ret);
			}
			//cout << j << " ";

		}


	}
	if (ret == 1e9)
	{
		cout << -1;
		return 0;
	}
	cout << ret;
	return 0;
}