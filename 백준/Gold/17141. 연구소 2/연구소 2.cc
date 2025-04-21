#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>


using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int n, m, ans = 1e9, days = 0, vcnt = 0;
vector<vector<int>>v;
vector<pair<int, int>>virus;
vector<int>temp;
int cnt = 1;
int dist[54][54];

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 1e9)
			{
				cout << -1 << " ";
			}
			else
			{
				cout << dist[i][j] << " ";
			}

		}
		cout << "\n";
	}
	cout << "\n";
}
void bfs(vector<int> temp)
{

	queue<pair<int, int >>q;
	for (auto i : temp)
	{
		q.push({ virus[i].first, virus[i].second });
		dist[virus[i].first][virus[i].second] = 0;
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || ny < 0 || nx >= n || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] == 1)
			{
				continue;
			}
			if (dist[ny][nx] !=1e9)
			{
				continue;
			}
			if (v[ny][nx] == 0 || v[ny][nx] == 2)
			{
				cnt++;
			}
			dist[ny][nx] = dist[y][x] + 1;
			days = max(days, dist[ny][nx]);
			q.push({ ny, nx });
		}
	}
}

void go(int here)
{
	if (temp.size() == m)
	{
		days = 0;
		cnt = 0;
		fill(&dist[0][0], &dist[n][n], 1e9);
		bfs(temp);
		//print();
		if ((cnt+m) == vcnt)
		{
			//cout << cnt << "\n";
			//for (int i = 0; i < n; i++)
			//{
			//	for (int j = 0; j < n; j++)
			//	{
			//		if (v[i][j] != 1)
			//		{
			//			days = max(days, dist[i][j]);
			//		}
			//	}
			//}		
			ans = min(days, ans);
			return;
		}


	}

	for (int i = here; i < virus.size(); i++)
	{
		temp.push_back(i);
		go(i + 1);
		temp.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(n, vector<int>(n));
	fill(&dist[0][0], &dist[n][n], 1e9);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 2)
			{
				virus.push_back({ i, j });
				vcnt++;
			}
			if (v[i][j] == 0)
			{
				vcnt++;
			}
		}
	}
	//vcnt - m;
	//if (vcnt == 0)
	//{
	//	cout << -1;
	//	return 0;
	//}
	go(0);
	if (ans == 1e9)
	{
		cout << -1;
		return 0;
	}
	cout << ans;
	return 0;
}