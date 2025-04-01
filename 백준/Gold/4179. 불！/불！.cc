#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int r, c, ja, jc, f1, f2, ans = 1e9;
int dx[4] = { 0, 1, 0 , -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<vector<char>>v;
queue<pair<int, int>>FF;
int visit[1004][1004];
int visit2[1004][1004];

void Fbfs(int y, int x)
{
    visit2[y][x] = 1;
    queue<pair<int, int>>q;
    q.push({ y, x });
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= r || ny < 0 || nx >= c || nx < 0)
            {
                continue;
            }
            if (v[ny][nx] == '#')
            {
                continue;
            }
            if (visit2[ny][nx] > visit2[y][x] + 1)
            {
                visit2[ny][nx] = visit2[y][x] + 1;
            }
            else
            {
                continue;
            }

            //visit2[ny][nx] = visit2[y][x] + 1;
            q.push({ ny, nx });

        }
    }
}
void bfs(int y, int x)
{
    visit[y][x] = 1;
    queue<pair<int, int>>q;
    q.push({ y, x });
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= r || ny < 0 || nx >= c || nx < 0)
            {
                continue;
            }
            if (visit[ny][nx] != 1e9)
            {
                continue;
            }
            if (v[ny][nx] == '#')
            {
                continue;
            }
            if (visit2[ny][nx] > visit[y][x] + 1)
            {
                visit[ny][nx] = visit[y][x] + 1;
            }
            else
            {
                visit[ny][nx] = 0;
                continue;
            }

            q.push({ ny, nx });

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    v.resize(r, vector<char>(c));
    //fill(visit, visit + r * c, 1e9)
    fill(&visit[0][0], &visit[r][c], 1e9);
    fill(&visit2[0][0], &visit2[r][c], 1e9);
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            v[i][j] = s[j];
            if (v[i][j] == 'J')
            {
                ja = i;
                jc = j;
            }
            if (v[i][j] == 'F')
            {
                FF.push({ i, j });
            }
        }
    }
    while (!FF.empty())
    {
        Fbfs(FF.front().first, FF.front().second);
        FF.pop();
    }
    //for (int i = 0; i < r; i++)
    //{
    //    for (int j = 0; j < c; j++)
    //    {
    //        if (visit2[i][j] == 1e9)
    //        {
    //            cout << 0 <<" ";
    //        }
    //        else
    //        {
    //            cout << visit2[i][j] << " ";
    //        }
    //    }
    //    puts("");
    //}
    //puts("==============================================");
    bfs(ja, jc);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || i == r - 1)
            {
                if (visit[i][j] != 0)
                {
                    ans = min(visit[i][j], ans);
                }
            }

            if (j == 0 || j == c - 1)
            {
                if (visit[i][j] != 0)
                {
                    ans = min(visit[i][j], ans);
                }
            }
            //if (visit[i][j] == 1e9)
            //{
            //    cout << 0 <<" ";
            //}
            //else
            //{
            //    cout << visit[i][j] <<" ";
            //}


        }
        //puts("");
    }
    if (ans == 1e9)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << ans;

    return 0;
}