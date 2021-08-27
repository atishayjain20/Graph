#include<bits/stdc++.h>
using namespace std;
const int n=1000;
vector<int>adj[n];
int vis[n]={0};
void bfs(int u){
    queue<int> q;
    q.push(u);
    vis[u]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        cout<<f<<endl;
        for(int i=0;i<adj[f].size();i++){
            int v=adj[f][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
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
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bfs(i);
        }
    }
    // bfs(1);
    return 0;
}