#include<bits/stdc++.h>
using namespace std;
int visited[1000]={0};
vector<int>adj[1000];
int n,m;
bool dfs(int u,int par)
{
    visited[u]=1;
    for(auto i:adj[u])
    {
        if(!visited[i]){
        if(dfs(i,u)) return true;}
        else if(i!=par) return true;
    }
    return false;
}
bool detectcycle(){
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1)) return true;
        }
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<detectcycle()<<endl;
    return 0;
}