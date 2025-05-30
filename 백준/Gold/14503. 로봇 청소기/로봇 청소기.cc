#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;



int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0 ,1,0,-1 };


int rdy[4] = { -1, 0, 1, 0 };
int rdx[4] = { 0 ,-1,0,1 };


int n, m;
int way;
int vcy, vcx;
int roomcnt = 0;
int ret =0;


pair<int, pair<int, int>> vcp;
vector<vector<int>>v;

pair<int, pair<int, int>> check(int y, int x, int w)
{
	//cout << "asdfdf"<<" ";
	pair<int, pair<int, int>>vcgo = { -1, {-1, -1} };
	for (int i = (w+1)%4;i < w+1+4; i++)
	{
		int ny = y + rdy[i%4];
		int nx = x + rdx[i%4];

		if (ny < 0 || ny >= n || nx < 0 || nx>=m)
		{
			continue;
		}

		if (v[ny][nx] == 1)
		{
			continue;
		}
		if (v[ny][nx] == 2)
		{
			continue;
		}

		if (v[ny][nx] == 0)
		{
			int ww;
			if (i % 4 == 0)
			{
				ww = 0;
			}
			else if (i % 4 == 1)
			{
				ww = 3;
			}
			else if (i % 4 == 2)
			{
				ww = 2;
			}
			else
			{
				ww = 1;
			}

			vcgo = {ww ,{ny, nx} };
			break;
		}
	}

	return vcgo;
}


void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << v[i][j] <<" ";
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

	cin >> n >> m;
	cin >> vcy >> vcx >> way;
	v.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == 0)
			{
				roomcnt++;
			}
		}
	}


	while (roomcnt)
	{
		if (v[vcy][vcx] == 0)
		{
			roomcnt--;
			ret++;
			v[vcy][vcx] = 2;
		}

		int w;

		if (way == 0)
		{
			w = 0;
		}
		else if (way == 1)
		{
			w = 3;
		}
		else if (way == 2)
		{
			w = 2;
		}
		else
		{
			w = 1;
		}

		vcp = check(vcy, vcx, w);

		if (vcp.first == -1)
		{
			int ny = vcy + dy[(way + 2) % 4];
			int nx = vcx + dx[(way + 2) % 4];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				break;
			}
			
			if (v[ny][nx] == 1)
			{
				break;
			}


			vcy = ny;
			vcx = nx;
		}
		else
		{
			way = vcp.first;
			vcy = vcp.second.first;
			vcx = vcp.second.second;
		}

		//print();
	}
	//print();
	cout << ret;
	return 0;
}