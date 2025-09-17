#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int dy[8] = { 0, 1, 1, 1, 0,-1,-1,-1 };
int dx[8] = { 1, 1, 0, -1, -1,-1, 0, 1};


int w, h;
vector<vector<int>>v;
int visit[54][54];
vector<int>ans;

void dfs(int y, int x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= h || ny < 0 || nx >= w || nx < 0)
		{
			continue;
		}
		if (visit[ny][nx] == 1)
		{
			continue;
		}
		if (v[ny][nx] == 0)
		{
			continue;
		}

		dfs(ny, nx);
	}
}

int main()
{
	//ios_base::sync_with_studio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	//cin >> w >> h;
	//v.resize(h, vector<int>(w));
	////int cnt = 0;
	//memset(visit, 0, sizeof(visit));
	//int cnt = 0;
	//for (int i = 0; i < h; i++)
	//{
	//	for (int j = 0; j < w; j++)
	//	{
	//		cin >> v[i][j];
	//	}
	//}

	//for (int i = 0; i < h; i++)
	//{
	//	for (int j = 0; j < w; j++)
	//	{
	//		if (v[i][j] == 1 && visit[i][j] == 0)
	//		{
	//			cnt++;
	//			dfs(i, j);
	//		}
	//	}
	//}
	//ans.push_back(cnt);
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
		{
			break;
		}
		v.clear();
		v.resize(h, vector<int>(w));

		memset(visit, 0, sizeof(visit));
		int cnt = 0;


		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> v[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (v[i][j] == 1 && visit[i][j] == 0)
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		ans.push_back(cnt);

	}
	for (int i : ans)
	{
		cout << i << "\n";
	}



	return 0;
}