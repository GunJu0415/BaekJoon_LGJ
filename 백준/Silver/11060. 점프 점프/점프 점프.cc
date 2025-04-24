#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, m, r, cnt;

vector<int>v;
int dist[100004];

void bfs(int x)
{
	dist[x] = 0;
	queue<int>q;
	q.push(x);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 1;i <= v[x];i++)
		{
			int nx= x + i;
			if (nx >= v.size())
			{
				continue;
			}

			if (dist[nx] > dist[x] + 1)
			{
				dist[nx] = dist[x] + 1;
				q.push(nx);
			}
		}
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
		v.push_back(a);
	}
	fill(&dist[0], &dist[n + 1], 1e9);
	bfs(0);
	if (dist[v.size() - 1] != 1e9)
	{
		cout << dist[v.size()-1];
	}
	else
	{
		cout << -1;
	}
	return 0;
}