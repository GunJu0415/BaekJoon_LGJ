#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<deque>

using namespace std;


// 방법 1 : 4개를 콤비네이션으로 골라서 만들고 테트로미노인지 확인
// 방법 2 : 테트로미노를 직접 배치해봄


// 내 생각에는 방법 1이 나을듯? 그럼 테트로미노인지 어떻게 확인하냐 

// 음.. 그냥 이전 변을 기억하고 되는것만 가게 할까?



int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1, 0, -1,0 };

int n, m;
int ret = 0;
vector<vector<int>>v;

vector<vector<int>>temp;

bool visit[504][504];

void dfs(int y, int x, int cnt, int sum)
{
	if (cnt == 4)
	{
		ret = max(ret, sum);
		return;
	}
	visit[y][x] = 1;
	for (int i = 0; i < 4; i ++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || ny < 0 || nx >= m || nx < 0)
		{
			continue;
		}
		if (visit[ny][nx])
		{
			continue;
		}
		
		dfs(ny, nx, cnt + 1, sum + v[ny][nx]);
		visit[ny][nx] = 0;
	}
}
void go(int y, int x)
{
	deque<pair<int, int>>dq;
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0)
		{
			continue;
		}
		dq.push_back({ ny, nx });
	}
	if (dq.size() >= 3)
	{
		
		for (int i = 0; i < dq.size(); i++)
		{
			int sum = v[y][x];
			for (int j = 0; j < 3; j++)
			{
				//cout << v[dq[(i + j) % dq.size()].first][dq[(i + j) % dq.size()].second]<<" ";
				sum += v[dq[(i + j) % dq.size()].first][dq[(i + j) % dq.size()].second];
			}
			//cout << "\n";
			ret = max(sum, ret);
		}
	}
}

//void go(int here, int cnt)
//{
//	if (here == n * m)
//	{
//		return;
//	}
//	if (cnt == 4)
//	{
//		
//	}
//
//	for (int i = here; i < n * m; i++)
//	{
//		int y = i / m;
//		int x = i % m;
//		temp[y][x] = 1;
//		go(i + 1, cnt + 1);
//		temp[y][x] = 0;
//
//	}
//
//
//}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			memset(visit, 0, sizeof(visit));
			dfs(i, j, 1, v[i][j]);
			go(i, j);
		}
	}
	cout << ret;

	//go(2, 0);
	//cout << ret;
	return 0;
} 