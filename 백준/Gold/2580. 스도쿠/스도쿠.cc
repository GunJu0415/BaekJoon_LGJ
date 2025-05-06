#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>>v;

vector<pair<int,int>>emp;

bool flag = 0;


int dx[8] = { -1, 0, 1, 1, 1, 0,-1,-1 };
int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };

void print()
{
    cout << "\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void check()
{
    int maska = 0;
    int maskb = 0;
    int maskc = 0;

    for (int i = 1; i <= 7; i += 3)
    {
        maskc = 0;
        for (int j = 0; j <= 7; j += 3)
        {
            maskc |= 1 << v[i][j];
            for (int k = 0; k < 8; k++)
            {
                int ny = i + dy[k];
                int nx = j + dx[k];
                maskc |= 1 << v[ny][nx];
            }
        }
        if (maskc == ((1 << 9) - 1))
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            return;
        }
    }

}


void go(int here)
{
    if (flag == 1)
    {
        
        return;
    }
    if (here == emp.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
        
        return;
    }
    int maska = 0;
    int maskb = 0;
    int maskc = 0;
    for (int i = 0; i < 9; i++)
    {
        maska |= (1 << v[emp[here].first][i]);
        maskb |= (1 << v[i][emp[here].second]);
    }


    int y = (emp[here].first / 3) * 3;
    int x = (emp[here].second / 3) * 3;

    for (int i = y; i < y + 3; i++)
    {
        for (int j = x; j < x + 3; j++)
        {
            maskc |= (1 << v[i][j]);
        }
    }
    int mask = (maska | maskb) | maskc;
    for (int i = 1; i <= 9; i++)
    {
        if ((mask & (1 << i)))
        {
            continue;
        }
        int temp = v[emp[here].first][emp[here].second];
        v[emp[here].first][emp[here].second]= i;
        go(here + 1);
        v[emp[here].first][emp[here].second] = temp;
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    v.resize(9, vector<int>(9));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 0)
            {
                emp.push_back({ i,j });
            }
        }
    }
    go(0);
    return 0;
}