#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };



int n, m;
vector<vector<int>>v;
int dist[104][104];
void dijkstra(int y, int x)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {y, x} });
	dist[y][x] = 0;
	while (!pq.empty())
	{
		//for (int i = 0; i < m; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//	{
		//		cout << dist[i][j];
		//	}
		//	cout << "\n";
		//}
		//puts("");
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (dist[y][x] < cost)
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= m || ny < 0 || nx >= n || nx < 0)
			{
				continue;
			}
			int nextcost = v[ny][nx] + cost;

			if (dist[ny][nx] > nextcost)
			{
				dist[ny][nx] = nextcost;
				pq.push({ nextcost, {ny, nx} });
			}
		}

	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(m, vector<int>(n));

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			v[i][j] = s[j] - '0';
		}
	}



	fill(&dist[0][0], &dist[m+1][n+1], 1e9);
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << v[i][j];
	//	}
	//	puts("");
	//}
	dijkstra(0, 0);
	cout << dist[m - 1][n - 1];
	return 0;
}