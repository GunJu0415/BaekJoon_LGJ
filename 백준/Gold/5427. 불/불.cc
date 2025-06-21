#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1,0,-1,0 };


int t, h, w;

pair<int, int> st;
queue<pair<int, int>>fire;
vector<vector<char>>v;
int dist[1004][1004];
int ret = 1e9;
int dist2[1004][1004];

void bfsFire()
{

	while (!fire.empty())
	{
		int y = fire.front().first;
		int x = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (dist[ny][nx] != 1e9)
			{
				continue;
			}
			if (ny >= h || ny < 0 || nx >= w || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] == '#')
			{
				continue;
			}
			dist[ny][nx] = dist[y][x] + 1;
			fire.push({ ny, nx });
		}
	}


}
void bfs(int y, int x)
{
	queue<pair<int, int>>q;
	q.push({ y, x });
	dist2[y][x] = 1;
	
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= h || ny < 0 || nx >= w || nx < 0)
			{
				continue;
			}
			if (dist2[ny][nx] != 1e9)
			{
				continue;
			}
			if (v[ny][nx] == '#')
			{
				continue;
			}
			dist2[ny][nx] = dist2[y][x] + 1;
			q.push({ ny, nx });
		}
	}

}


void print()
{

	cout << "\n";
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (dist[i][j] == 1e9)
			{
				cout << "%";
				continue;
			}
			cout << dist[i][j];
		}
		cout << "\n";
	}

	cout << "\n";

	cout << "\n";
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (dist2[i][j] == 1e9)
			{
				cout << "%";
				continue;
			}
			cout << dist2[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;

	while (t--)
	{
		cin >> w >> h;
		v.clear();
		v.resize(h, vector<char>(w));
		ret = 1e9;
		fill(&dist[0][0], &dist[h + 1][w + 1], 1e9);
		fill(&dist2[0][0], &dist2[h + 1][w + 1], 1e9);

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> v[i][j];
				if (v[i][j] == '@')
				{

					st = { i, j };
				}
				if (v[i][j] == '*')
				{
					//cout << "adf";
					dist[i][j] = 1;
					fire.push({ i, j });
				}
			}
		}

		bfsFire();
		bfs(st.first, st.second);


		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || i == h - 1)
				{
					if (dist[i][j] > dist2[i][j])
					{
						ret = min(dist2[i][j], ret);
					}
				}
				else
				{
					if (j == 0 || j == w - 1)
					{
						if (dist[i][j] > dist2[i][j])
						{
							ret = min(dist2[i][j], ret);
						}
					}
				}



			}
		}
		if (ret == 1e9)
		{
			cout << "IMPOSSIBLE";
		}
		else
		{
			cout << ret;
		}
		cout << "\n";
		//print();
	}
}