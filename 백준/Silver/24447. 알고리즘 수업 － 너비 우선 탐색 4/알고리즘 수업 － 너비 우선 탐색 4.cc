#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
typedef long long int ll;

int n, m, r;
vector<int> v[100004];
int dist[100004];
int depth[100004];
ll ret = 0;
void bfs(int x)
{
	int temp = 1;
	depth[x] = temp++;
	queue<int>q;
	q.push(x);
	dist[x] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		
		for (int i : v[x])
		{
			if (dist[i] != 1e9)
			{
				continue;
			}
			depth[i] = temp++;
			dist[i] = dist[x] + 1;
			q.push(i);
		}
	}
}
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;

	fill(&dist[0], &dist[n + 1], 1e9);
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
	bfs(r);

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 1e9)
		{
			continue;
		}
		ret += 1LL *depth[i] * dist[i];
	}
	cout << ret;
}