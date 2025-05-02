#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;



int n, ans =1e9;
int arr[24];


// 완탐 종료 기준
// 뒤집었을때와 안뒤집었을때 호출은 알겠으나 직접 값을 뒤집으면 나중에 못돌아옴 그래서 매개변수로 하는게 맞는지
//


void go(int idx)
{
	if (idx == n)
	{
		int ret = 0;
		for (int i = 1; i < (1 << n); i *= 2)
		{
			int temp = 0;
			for (int j = 0; j < n; j++)
			{
				if (i & arr[j])
				{
					temp++;
				}
			}
			ret += min(temp, n - temp);
		}
		ans = min(ret, ans);
		return;
	}

	go(idx + 1);

	arr[idx] = ~arr[idx];

	go(idx + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int temp = 0;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == 'H')
			{
				temp |= (1 << j);
			}
		}
		arr[i] = temp;
	}

	//for (int i : arr)
	//{
	//	cout << i << " ";
	//}
	go(0);
	cout << ans;
	return 0;


}