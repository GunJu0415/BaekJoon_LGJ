#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>


using namespace std;

int n;
vector<vector<int>>v;
int comp[24];
int ans = 1e9;

int asum = 0;
int bsum = 0;


void go()
{
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			// 같은 팀이면 합함
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

	// n이 2개의 팀으로  나누어 지는 모든 경우의수 2^n
	for (int i = 1; i < (1 << n); i++)
	{
		memset(comp, 0, sizeof(comp));
		asum = 0;
		bsum = 0;
		for (int j = 0; j < n; j++)
		{
			
			if (i & (1 << j))
			{// j 번째 수가 1번팀 추가 되는 경우
				comp[j + 1] = 1;
			}
		}
		// 완전 탐색
		go();
		// 팀능력치의 차 최솟값 확인
		ans = min(abs(asum - bsum), ans);
	}
	cout << ans;
	return  0;
}