#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, x;
vector<int> v[1004];
bool visit[1004];
void dfs(int x)
{ 
	visit[x] = 1;
	cout << x << " ";
	for (int i : v[x])
	{
		if (visit[i])
		{
			continue;
		}
		dfs(i);
	}
}
void bfs(int x)
{
	visit[x] = 1;
	queue<int>q;
	q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		
		for (int i : v[x])
		{
			if (visit[i])
			{
				continue;
			}
			visit[i] = 1;
			q.push(i);
		}
	}
}
int main()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	dfs(x);
	memset(&visit[0], 0, sizeof(visit));
	cout << "\n";
	bfs(x);
	return 0;
}