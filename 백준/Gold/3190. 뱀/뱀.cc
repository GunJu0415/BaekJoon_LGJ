#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<deque>

using namespace std;

//우 하 좌 상
int dx[4] = {  1, 0, -1, 0 };
int dy[4] = {  0, 1 ,0, -1 };
int n, k, m, L, D, cnt = 0, ans = 0;;
//bool visit[104][104];
vector<vector<int>>v;
queue<pair<int, char>>q;
deque<pair<int, int>>snake;


//void tale(int y, int x)
//{
//	visit[y][x] = 1;  // 방문 체크
//	int temp = 0;
//
//	for (int i = 0; i < 4; i++)
//	{
//		int ny = y + dy[i];
//		int nx = x + dx[i];
//
//		if (ny < 0 || ny >= n || nx < 0 || nx >= n) // nx 크기 확인 (m인지 n인지 체크 필요)
//		{
//			temp++;
//			continue;
//		}
//		if (visit[ny][nx])
//		{
//			temp++;
//			continue;
//		}
//		if (v[ny][nx] != 2)
//		{
//			temp++;
//			continue;
//		}
//
//		visit[ny][nx] = 1;
//		tale(ny, nx);
//	}
//
//	if (temp >= 4)  // 네 방향을 다 검사한 후에 판단해야 함
//	{
//		v[y][x] = 0;
//	}
//}


void dfs(int y, int x, int way,int step)
{

	ans = step;
	//visit[y][x] = 1;
	v[y][x] = 2;
	snake.push_front({ y,x });
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << v[i][j];
	//	}
	//	puts("");
	//}
	//puts("");
	int ny = y + dy[way];
	int nx = x + dx[way];
	if (ny < 0 || ny >= n || nx < 0 || nx >= n)
	{
		return;
	}
	if (v[ny][nx] == 2)
	{
		return;
	}
	//visit[ny][nx] = 1;	
	if (v[ny][nx] == 1)
	{
		cnt++;
	}
	else
	{
		v[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}

	if (!q.empty())
	{
		
		if (q.front().first == step)
		{
			int ww = q.front().first;
			char cc = q.front().second;
			q.pop();
			//cout << "asdfasdfasdfasdf\t" << q.front().first << "\n";
			if (cc == 'D')
			{
				dfs(ny, nx, (way+1)%4, step + 1);
			}
			if (cc == 'L')
			{
				dfs(ny, nx, (way - 1 +4) % 4, step + 1);
			}
			
		}
		else
		{
			//cout << "asdfasdfasdfasdf\t" << q.front().first << "\n";
			dfs(ny, nx, way, step + 1);
		}
	}
	else
	{
		dfs(ny, nx, way, step + 1);
	}
	
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	n;
	v.resize(n, vector<int>(n));
	memset(&v[0][0], 0, v.size());
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a - 1][b - 1] = 1;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		q.push({ a, b });
	}
	//while (!q.empty())
	//{
	//	cout << q.front().first << q.front().second << " ";
	//	q.pop();
	//}
	dfs(0, 0, 0, 1);
	//for (int i = 0; i < v.size(); i++)
	//{
	//	for (int j = 0; j < v[i].size(); j++)
	//	{
	//		cout << v[i][j];
	//	}
	//	puts("");
	//}
	cout << ans;
	return 0;
}