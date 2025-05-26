#include <string>
#include <vector>

using namespace std;

bool visit[204];
int ans =0;
int nn;
vector<vector<int>>v;

void dfs(int x)
{
    visit[x]  = 1;
    for(int i =0;i<nn;i++)
    {
        if(i == x)
        {
            continue;
        }
        if(visit[i])
        {
            continue;
        }
        if(v[x][i] == 1)
        {
            dfs(i);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    v =computers;
    nn =n;
    for(int i =0;i<n;i++)
    {
        if(!visit[i])
        {
            dfs(i);
            ans ++;
        }

    }
   
    answer = ans;
    
    
    
    
    
    return answer;
}