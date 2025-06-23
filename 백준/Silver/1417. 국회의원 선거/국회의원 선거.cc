#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

int n;
int dasom;
int cnt = 0;
int maxnum;
int ans = 0;
priority_queue<int>pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> dasom;
	for (int i = 1; i < n; i++)
	{
		
		int a;
		cin >> a;
		pq.push(a);
		maxnum = a;
		cnt++;

	}
	if (!pq.empty())
	{
		while (dasom <= pq.top() && !pq.empty())
		{
			int temp = pq.top();
			pq.pop();
			dasom += 1;
			ans += 1;

			temp--;
			pq.push(temp);
		}
		
	}
	cout << ans;



	return 0;
}