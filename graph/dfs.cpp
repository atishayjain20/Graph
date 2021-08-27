#include<bits/stdc++.h>
using namespace std;
//                         graph representation using matrix
// int adj[n+1][n+1];
// for(i=0;i<m;i++)
// {
//     int u,v;
//     cin>>u>>v;
//     int adj[u][v]=1;
//     int adj[v][u]=1;
// }

//                                     weighted graph
// vector<pair<int,int>> adj[n+1];
// for(i=0;i<m;i++){
//     int u,v,wt;
//     cin>>u>>v>>wt;
//     adj[u].push_back({v,wt});
//     adj[v].push_back({u,wt});
// }
const int n=1000;
vector<int> adj[n];
int vis[n]={0};
void dfs(int u){
    vis[u]=1;
    std::cout << u << std::endl;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int count=0;
    for(int i=1;i<=n;i++)
    {
        //to determine how much disconnected nodes are their
        if(!vis[i]){
            dfs(i);
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}