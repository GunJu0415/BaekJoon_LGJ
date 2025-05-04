#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


int dx[4] = { 0, 1,0,-1 };
int dy[4] = { -1, 0, 1 , 0 };


using namespace std;
int arr[5];
int ret = 0;
int yy, xx;
vector<vector<int>>v;
bool visit[30][30];
vector<vector<int>>comb;

int dfs(int y, int x)
{
	int cnt = 1;
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 5 || ny < 0 || nx >= 5 || nx < 0)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		if (comb[ny][nx] == 0)
		{
			continue;
		}
		cnt += dfs(ny, nx);
	}
	return cnt;
}


void go(int here, int scnt,int cnt)
{
	if (cnt == 7 &&scnt>=4)
	{
		fill(&visit[0][0], &visit[5][5], 0);
		int temp = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (!visit[i][j] && comb[i][j] != 0 &&temp <1)
				{
					temp = dfs(i, j);
					if (temp == 7)
					{
						ret++;
					}
				}
			}
		}

		return;
	}

	for (int i = here; i < 25; i++)
	{
		int y = i / 5;
		int x = i % 5;
		if (v[y][x] == 1)
		{
			comb[y][x] = 1;
			scnt++;
		}
		else
		{
			comb[y][x] = 2;
		}
		
		yy = y;
		xx = x;
		go(i + 1, scnt,cnt +1);
		comb[y][x] = 0;
		if (v[y][x] == 1)
		{
			scnt--;
		}

	}



}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	v.resize(5, vector<int>(5));
	comb.resize(5, vector<int>(5));
	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;
		int temp = 0;
		for (int j = 4; j >= 0; j--)
		{

			if (s[j] == 'S')
			{
				v[i][j] = 1;
			}
		}
	}

	go(0, 0,0);
	cout << ret;
	return 0;
}
