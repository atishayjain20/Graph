#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1000];
int n,m;
int djkistra(int source,int dest)
{
    vector<int> dist(n+1,INT_MAX);
    priority_queue<pair<int,int>greater<int>>pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.front().second;
        pq.pop();
        for(auto i=adj[u].begin();i!=adj[u].end();i++)
        {
                if(dist[i]>adj[i].second+dist[u])
                {
                    dist[i]=adj[i].second+dist[u];
                    pq.push(make_pair(dist[i],i));
                }
        }

    }
    return dist[dest];
}
int main(){
    cin>>n>>m;
    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin>>source>>dest;
    cout<<djkistra(source,dest)<<endl;
    return 0;
}
