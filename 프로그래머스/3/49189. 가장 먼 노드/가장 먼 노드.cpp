#include <string>
#include <vector>
#include <queue>
#include <algorithm>



using namespace std;

int temp = 0;
int dist[20004];
vector<pair<int, int>>v[20004];


void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int,int>>>pq;
    pq.push({0, start});
    dist[start]=0;
    
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(dist[node] < cost)
        {
            continue;
        }
        
        for(auto i : v[node])
        {
            int nextnode= i.first;
            int nextcost = i.second + cost;
            if(dist[nextnode] > nextcost)
            {
                temp = max(temp, nextcost);
                dist[nextnode] = nextcost;
                pq.push({nextcost, nextnode});
            }
        } 
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    fill(dist, dist + n+1, 1e9);
    for(int i =0;i<edge.size();i++)
    {
        v[edge[i][0]].push_back({edge[i][1], 1});
        v[edge[i][1]].push_back({edge[i][0], 1});
    }
    dijkstra(1);
    
    for(int i =1;i<=n;i++)
    {
        if(dist[i] == temp)
        {
            answer++;
        }
    }
    return answer;
}