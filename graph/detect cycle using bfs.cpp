#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int visited[1000]={0};
int n,m;
bool bfscycle(int u){
    queue<pair<int,int>> q;
    q.push({u,-1});
    visited[u]=1;
    while(!q.empty()){
        int u=q.front().first;
        int par=q.front().second;
        q.pop();
        for(auto i:adj[u]){
            if(!visited[i])
            {
                q.push({i,u});
                visited[i]=true;
            }
            else if(par!=i)
            return true;
        }
    }
    return false;
}
bool detectcycle(){
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        if(bfscycle(i)) return true;
    }
    return false;
}
int main(){
    int u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<detectcycle()<<endl;
    return 0;
}