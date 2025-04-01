#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


int n;
int cnt = 0;
int ans = 0;
vector<int>v;
bool visit[3004];
void go(int x)
{
    int left = 0;
    int  right = n-1;
    int num = v[x];
    while (left < right)
    {
        
        if (left == x)
        {
            left++;
        }
        if (right == x)
        {
            right--;
        }
        //cout << left << " " << right << "\n";
        if (left == right)
        {
            return;
        }
        int mid = v[right] + v[left];
        if (mid < num)
        {
            left++;

        }
        else if (mid > num)
        {
            right--;

        }
        else
        {
            //cout << left << " " << right << "\n";
            //cout << mid << "\n";
            cnt++;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        go(i);
    }
    cout << cnt;
    return 0;
}