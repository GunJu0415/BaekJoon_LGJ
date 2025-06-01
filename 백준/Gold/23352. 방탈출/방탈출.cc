#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;


int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int n, m;
int ans = 0;
int gy, gx;
int dist[54][54];
vector<vector<int>>v;
//int p[54][54];
priority_queue< pair<int, pair<pair<int, int>, pair<int, int>>>> pass;

pair<int, pair<pair<int, int>, pair<int, int>>>word;

pair<int, pair<pair<int, int>, pair<int, int>>> bfs(int y, int x)
{
	pair<int, pair<pair<int, int>, pair<int, int>>> ret = { 0, {{y, x}, { y, x }} };
	//int temp = 0;
	queue<pair<int, int>>q;
	q.push({ y, x });
	dist[y][x] = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= n || ny < 0 || nx >= m || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] == 0)
			{
				continue;
			}
			if (dist[ny][nx] != 1e9)
			{
				continue;
			}
			dist[ny][nx] = dist[y][x] + 1;
			if (ret.first < dist[ny][nx])
			{
				ret.first = dist[ny][nx];
				ret.second.second = { ny, nx };
			}

			q.push({ ny, nx });
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;;

	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	word = { 0, {{0, 0}, {0, 0} } };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (v[i][j] == 0)
			{
				continue;
			}
			fill(&dist[0][0], &dist[n][m], 1e9);
			pair<int, pair<pair<int, int>, pair<int, int>>>temp = bfs(i, j);
			
			if (word.first < temp.first)
			{
				word = temp;
				ans = v[word.second.first.first][word.second.first.second] + v[word.second.second.first][word.second.second.second];
			}
			else if (word.first == temp.first)
			{
				word = temp;
				ans = max(ans, v[word.second.first.first][word.second.first.second] + v[word.second.second.first][word.second.second.second]);
			}
			//pass.push(temp);
		}
	}
	//if (pass.empty())
	//{
	//	cout << 0;
	//	return 0;
	//}
	//int cost = pass.top().first;
	//int ans = v[pass.top().second.first.first][pass.top().second.first.second] + v[pass.top().second.second.first][pass.top().second.second.second];
	//pass.pop();
	//while (1)
	//{
	//	if (cost == pass.top().first)
	//	{
	//		ans = max(ans, v[pass.top().second.first.first][pass.top().second.first.second] + v[pass.top().second.second.first][pass.top().second.second.second]);
	//		pass.pop();
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	cout << ans;
	return 0;
}