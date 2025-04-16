#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, cnt;
vector<int>v[10004];
vector<pair<int, int>>ans;
bool visit[10004];
vector<int> ra;

void dfs(int x)
{
	//cout << x << "\n";
	visit[x] = 1;
	cnt++;
	for (int i : v[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		fill(&visit[0], &visit[n+1], 0);
		dfs(i);
		//cout << cnt << " ";
		ans.push_back({ cnt, i });
	}
	sort(ans.begin(), ans.end(), greater<>());
	//dfs(1);
	//cout << "   " << cnt << "\n";
	//cnt =
	//dfs(2);
	//cout <<"    "<< cnt << "\n";
	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i].first == ans[0].first)
		{
			ra.push_back(ans[i].second);
		}
	}
	sort(ra.begin(), ra.end());
	for (int i : ra)
	{
		cout << i << " ";
	}
	return 0;
}