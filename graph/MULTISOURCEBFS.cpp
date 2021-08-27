#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> adj[1000];
int source[1000];
queue<int> q;
int dist[1000]={0};
int visited[1000];
void bfs()
{
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            int v=adj[x][i];
        if(!visited[v]){
        q.push(v);
        visited[v]=1;
        dist[v]=dist[x]+1;
        }
    }
}
}
void multisource(){
    for(int i=0;i<k;i++){
        q.push(source[i]);
        visited[source[i]]=1;
    }
    bfs();
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>k;
    for(int i=0;i<k;i++)
    cin>>source[i];
    multisource();
    for(int i=1;i<=n;i++)
    cout<<i<<" "<<dist[i]<<endl;
    return 0;
}
