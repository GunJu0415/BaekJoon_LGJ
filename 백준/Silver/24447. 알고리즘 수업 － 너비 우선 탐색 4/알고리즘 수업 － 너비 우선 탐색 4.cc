#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef long long ll;

int n, m, r;
vector<int> v[100004];
int dist[100004];
int depth[100004];
ll ret = 0;

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    dist[x] = 0;

    int order = 1;
    depth[x] = order++;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next : v[now])
        {
            if (dist[next] != -1) continue;

            dist[next] = dist[now] + 1;
            depth[next] = order++;
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> r;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());  // 오름차순 방문
        dist[i] = -1;
    }

    bfs(r);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == -1) continue;
        ret += 1LL * dist[i] * depth[i];
    }

    cout << ret << '\n';
}
