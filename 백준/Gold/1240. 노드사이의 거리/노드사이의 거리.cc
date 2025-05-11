#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int n, m;
int sstart =0, eend =0;

vector<pair<int, int>>v[10004];
vector<int> ret;
bool  visit[10004];
int dist[10004];

void dfs(int x, int cnt)
{
	if (x == eend)
	{
		ret.push_back(cnt);
	}
	visit[x] = 1;
	for (auto i : v[x])
	{
		if (visit[i.first])
		{
			continue;
		}
		dfs(i.first, cnt + i.second);
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	//cout << "asdf";
	for (int i = 0; i < m; i++)
	{
		fill(&visit[0], &visit[n+1], 0);
		cin >> sstart >> eend;
		//cout << sstart << " " << eend << "\n";
		dfs(sstart, 0);

	}

	for (int i = 0; i < m; i++)
	{
		cout << ret[i] << "\n";

	}

	return 0;
}