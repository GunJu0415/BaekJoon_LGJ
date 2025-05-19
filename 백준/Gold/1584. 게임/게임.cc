#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;


int dy[4] = { 0, 1,0,-1 };
int dx[4] = { 1, 0, -1, 0 };


int n, m;
vector<vector<int>> v;
int dist[504][504];
int p[10004];
int st, ed;
int ret = 1e9;


void print()
{
	cout << "\n";
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			if (v[i][j] == 1e9)
			{
				cout << 2 << " ";
			}
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dijkstra(int y, int x)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
	pq.push({ 0,{ y, x} });
	dist[y][x] = 0;

	while (!pq.empty())
	{
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
			if (ny > 500 || ny < 0 || nx > 500 || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] == -1)
			{
				continue;
			}
			int nextcost = cost + v[ny][nx];
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
	cin >> n;
	v.resize(504, vector<int>(504, 0));
	fill(&dist[0][0], &dist[0][0] + 504 * 504, 1e9);

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int y1 = min(a, c);
		int x1 = min(b, d);
		int y2 = max(c, a);
		int x2 = max(b, d);

		for (int j = y1; j <= y2; j++)
		{
			for (int k = x1; k <= x2; k++)
			{
				v[j][k] = 1;
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int y1 = min(a, c);
		int x1 = min(b, d);
		int y2 = max(c, a);
		int x2 = max(b, d);
		for (int j = y1; j <= y2; j++)
		{
			for (int k = x1; k <= x2; k++)
			{
				v[j][k] = -1;
			}
		}
	}


	//print();
	dijkstra(0, 0);

	if (1e9==dist[500][500])
	{
		cout << -1;
		return 0;
	}
	cout << dist[500][500];
	return 0;
}