#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int n;
vector<pair<int, int>>v[100004];
bool visit[100004];
int ret = 0;
int startnode = 0;
void dfs(int x, int cnt)
{
	visit[x] = 1;
	if (cnt > ret)
	{
		startnode = x;
		ret = cnt;
	}

	for (auto i : v[x])
	{
		if (visit[i.first])
		{
			continue;
		}
		dfs(i.first, cnt + i.second);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		while (1)
		{
			int b, c;
			cin >> b;
			if (b == -1)
			{
				break;
			}
			cin >> c;
			v[a].push_back({ b, c });
		}
	}
	fill(&visit[0], &visit[n + 1], 0);
	dfs(1, 0);
	ret = 0;
	fill(&visit[0], &visit[n + 1], 0);
	dfs(startnode, 0);
	cout << ret;
	return 0;
}