#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cstring>
using namespace std;



// 미세먼지 확산 4방향이고 동시에 == bfs
// 공기청정기나 칸이없으면 확산 안함
// 확산은 5분의 1만 됨 남은 데는 확산시키고 남은 만큼


// 공기청정기 위쪽 = 반시계 공기청정기 아래쪽 = 시계
// 미세먼지는 공기청정기 바람 방향으로 움직임 

// 먼지 위치 뭘로 저장하지?
// 

int ret = 0;

// 시계
int dy2[4] = { 0 ,1,0,-1 };
int dx2[4] = { 1, 0 ,-1,0 };



// 반시계
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int r, c, t;
vector<vector<int>>v;

int a1 = -1, a2 = -1;
int b1 = -1, b2 = -1;
queue<pair<int, int>>dust;
deque<pair<int, int >>dq;
// 먼지 확산
void bfs()
{
	vector<vector<int>>v2;
	v2.resize(r, vector<int>(c));
	queue<pair<int, int >>q;
	deque<pair<int, int>>dq2;
	//v2 = v;

	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
			{
				continue;
			}
			if (v[ny][nx] == -1)
			{
				continue;
			}
			cnt++;
			v2[ny][nx] += v[y][x] / 5;
		}
		int temp = v[y][x] - ((v[y][x] / 5) * cnt);
		v2[y][x] += temp;
		if (v2[y][x] > 0)
		{

		}
		else
		{
			v2[y][x] = 0;
		}
	}
	v2[a1][a2] = -1;
	v2[b1][b2] = -1;
	v = v2;
	//dq = dq2;
}
// 반시계
//void airA(int y, int x)
//{
//	for (int i = y - 1; i > 0; i--) v[i][0] = v[i - 1][0];
//	for (int i = 0; i < c - 1; i++) v[0][i] = v[0][i + 1];
//	for (int i = 0; i < y; i++) v[i][c - 1] = v[i + 1][c - 1];
//	for (int i = c - 1; i > 1; i--) v[y][i] = v[y][i - 1];
//	v[y][1] = 0;
//}
//
//void airB(int y, int x)
//{
//	for (int i = y + 1; i < r - 1; i++) v[i][0] = v[i + 1][0];
//	for (int i = 0; i < c - 1; i++) v[r - 1][i] = v[r - 1][i + 1];
//	for (int i = r - 1; i > y; i--) v[i][c - 1] = v[i - 1][c - 1];
//	for (int i = c - 1; i > 1; i--) v[y][i] = v[y][i - 1];
//	v[y][1] = 0;
//}

// 반시계
void airA(int y, int x)
{
	vector<vector<int>>v2;
	v2.resize(r, vector<int>(c));

	int tempy = y;
	int tempx = x + 1;
	int temp = v[tempy][tempx];
	v[tempy][tempx] = 0;

	for (int i = 0; i < 4; i++)
	{
		while (1)
		{
			int ny = tempy + dy[i];
			int nx = tempx + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
			{
				break;
			}
			if (v[ny][nx] == -1)
			{
				break;
			}
			int ntemp = v[ny][nx];
			v[ny][nx] = temp;
			temp = ntemp;
			tempy = ny;
			tempx = nx;

		}
	}
	v[a1][a2] = -1;
	v[b1][b2] = -1;
	//v = v2;

}

// 시계
void airB(int y, int x)
{
	vector<vector<int>>v2;
	v2.resize(r, vector<int>(c));

	int tempy = y;
	int tempx = x + 1;
	int temp = v[tempy][tempx];
	v[tempy][tempx] = 0;

	for (int i = 0; i < 4; i++)
	{
		while (1)
		{
			int ny = tempy + dy2[i];
			int nx = tempx + dx2[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)
			{
				break;
			}
			if (v[ny][nx] == -1)
			{
				break;
			}
			int ntemp = v[ny][nx];
			v[ny][nx] = temp;
			temp = ntemp;
			tempy = ny;
			tempx = nx;

		}
	}
	v[a1][a2] = -1;
	v[b1][b2] = -1;
	//v = v2;

}
void print()
{
	cout << "\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j] == -1)
			{
				cout << "-" << "  ";
				continue;
			}
			cout << v[i][j] << "  ";
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
	cin >> r >> c >> t;
	v.resize(r, vector<int>(c));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> v[i][j];
			if (v[i][j] > 0)
			{
				//dq.push_back({ i, j });
				//dust.push({ i, j });
			}
			if (v[i][j] == -1)
			{
				if (a1 == -1)
				{
					a1 = i;
					a2 = j;
				}
				else
				{
					b1 = i;
					b2 = j;
				}
			}
		}
	}
	//bfs();
	//print();
	while (t--)
	{
		dq.clear();
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (v[i][j] > 0)
				{
					dq.push_back({ i, j });
				}
			}
		}
		bfs();
		airA(a1, a2);
		airB(b1, b2);
	}
	//print();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (v[i][j] > 0)
			{
				ret += v[i][j];
			}
		}
	}

	cout << ret;
	return 0;
}
