#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[1000];
int n,m;
int djkistra(int src,int dest)
{
    vector<int> dist(n+1,INT_MAX);
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        for(auto i=adj[u].begin();i!=adj[u].end();i++)
        {
            int weight=(*i).second;
            int v=(*i).first;
                if(dist[v]>weight+dist[u])
                {
                    dist[v]=weight+dist[u];
                    pq.push(make_pair(dist[v],v));
                }
        }

    }
    return dist[dest];
}
int main(){
    cin>>n>>m;
    int u,v,w,src,dest;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin>>src>>dest;
    cout<<djkistra(src,dest)<<endl;
    return 0;
}