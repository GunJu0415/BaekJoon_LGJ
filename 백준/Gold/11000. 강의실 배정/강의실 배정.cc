#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
using namespace std;


int n;
//int st = 0;
vector<int> st;
vector<pair<int, int>>v;

priority_queue<int, vector<int>, greater<int>>pq;
int ret = 1;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		//pq.push({ b, a });
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	//st.push_back(v[0].second);

	pq.push(v[0].second);


	for (int i = 1; i < n; i++)
	{
		if (pq.top() <= v[i].first)
		{
			pq.pop();
		}
		pq.push(v[i].second);
	}


	cout << pq.size();
	return 0;
}