#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int n, k;
vector<int>v[100004];
vector<int> apple;
int ret = 0;
int visit[100004];

void dfs(int x, int cnt)
{
	if (cnt > k)
	{
		return;
	}
	visit[x]= 1;
	if (apple[x] == 1)
	{
		ret++;
	}
	for (int i : v[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i, cnt + 1);
		visit[i] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		apple.push_back(a);
	}
	dfs(0, 0);
	cout << ret;
	return 0;
}