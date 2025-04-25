#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>


using namespace std;


int n;
int ans = 1e9;
vector<int> v[24];
int comp[24];
int a[24];
bool visit[24];
int dfsIdx1 = 0;
int dfsIdx2 = 0;

pair<int, int>dfs(int here, int value)
{
	visit[here] = 1;
	pair<int, int> ret = { 1, a[here]};

	for (int i : v[here])
	{
		if (visit[i])
		{
			continue;
		}
		if (comp[i] != value)
		{
			continue;
		}
		pair<int, int> temp = dfs(i, value);
		ret.first += temp.first;
		ret.second += temp.second;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			int c;
			cin >> c;
			v[i].push_back(c);
			v[c].push_back(i);
		}
	}
	for (int i = 1; i < (1 << n) - 1; i++)
	{
		memset(visit, 0, sizeof(visit));
		memset(comp, 0, sizeof(comp));
		dfsIdx1 = -1;
		dfsIdx2 = -1;

		for (int j = 0; j < n; j++)
		{
			//cout << (1 << j);
			if (i & (1 << j))
			{
				dfsIdx1 = j + 1;
				comp[j+1] = 1;
				
			}
			else
			{
				dfsIdx2 = j + 1;
			}
			//cout << dfsIdx1 << " " << dfsIdx2;
		}
		pair<int, int>ateam = dfs(dfsIdx1, 1);
		pair<int, int>bteam = dfs(dfsIdx2, 0);

		if (ateam.first + bteam.first == n)
		{
			ans = min(abs(ateam.second - bteam.second), ans);
		}
	}
	if (ans == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}