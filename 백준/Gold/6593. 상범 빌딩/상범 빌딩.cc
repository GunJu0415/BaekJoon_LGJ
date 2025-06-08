#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int dy[4] = { 0, 1,0 ,-1 };
int dx[4] = { 1, 0, -1, 0 };

int l, r, c;
int dist[34][34][34];
vector<vector<vector<char>>>v;
pair<int, pair<int, int>> st;
pair<int, pair<int, int>> ed;
void print()
{
	cout << "\n";
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < r; j++)
		{
			for (int k = 0; k < c; k++)
			{
				if (dist[i][j][k] == 1e9)
				{
					cout << "*";
					continue;
				}
				cout << dist[i][j][k];
			}
			cout << "\n";
		}
		cout << "\n";
	}

}
void bfs(int z,int y, int x)
{
	queue<pair<int, pair<int, int>>>q;
	q.push({ z, { y, x } });
	dist[z][y][x] = 0;
	while (!q.empty())
	{
		//print();
		int z = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		for (int i : { 1, 0, -1})
		{
			int nz = z + i;
			if (nz >= l || nz < 0)
			{
				continue;
			}
			if (dist[nz][y][x] != 1e9)
			{
				continue;
			}			
			if (v[nz][y][x] == '#')
			{
				continue;
			}
			dist[nz][y][x] = dist[z][y][x] + 1;
			q.push({ nz, {y,x} });
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
			{
				continue;
			}
			if (dist[z][ny][nx] != 1e9)
			{
				continue;
			}
			if (v[z][ny][nx] == '#')
			{
				continue;
			}
			dist[z][ny][nx] = dist[z][y][x] + 1;
			q.push({ z, {ny,nx} });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (1)
	{
		
		cin >> l >> r >> c;
		
		if (l == 0 && r == 0 && c == 0)
		{
			break;
		}
		fill(&dist[0][0][0], &dist[0][0][0] + 34 * 34 * 34, 1e9);
		v.clear();
		v.resize(l, vector<vector<char>>(r, vector<char>(c)));
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> v[i][j][k];
					if (v[i][j][k] == 'S')
					{
						st = { i, {j, k} };
					}
					if (v[i][j][k] == 'E')
					{
						ed = { i, {j, k} };
					}
				}
			}
		}

		bfs(st.first, st.second.first, st.second.second);

		if (dist[ed.first][ed.second.first][ed.second.second] != 1e9)
		{
			cout << "Escaped in " << dist[ed.first][ed.second.first][ed.second.second] << " minute(s).\n";
		}
		else
		{
			cout << "Trapped!\n";
		}
		
		
	}
	

	return 0;
}