#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>


using namespace std;

int dy[4] = { 1,  0, -1,0 };
int dx[4] = { 0, 1, 0, -1 };
int n;
vector<vector<int>>v;
bool visit[24][24];
int comp[24];
int dfsIdx1 = 0;
int dfsIdx2 = 0;
int ans = 1e9;

int asum = 0;
int bsum = 0;


void go()
{

	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (comp[i] == 1 && comp[j] == 1)
			{
				asum += v[i][j];
			}
			else if (comp[i] == 0 && comp[j] == 0)
			{
				bsum += v[i][j];
			}
			else
			{
				continue;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	v.resize(n+1, vector<int>(n+1));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 1; i < (1 << n); i++)
	{
		memset(visit, 0, sizeof(visit));
		memset(comp, 0, sizeof(comp));
		dfsIdx1 = -1;
		dfsIdx2 = -1;
		asum = 0;
		bsum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				dfsIdx1 = j + 1;
				comp[j + 1] = 1;
			}
			else
			{
				dfsIdx2 = j + 1;
			}
		}
		go();
		ans = min(abs(asum - bsum), ans);
	}
	cout << ans;
	return  0;
}