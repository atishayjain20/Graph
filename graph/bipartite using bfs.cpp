#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int n,m;
int color[1000]={-1};
bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    color[u]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto i:adj[x]){
            if(color[i]==-1){
                q.push(i);
                color[i]=1-color[u];
            }
            else if(color[i]==color[u])
            return false;
        }
    }
    return true;
}
bool checkbip(){
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(bfs[i]) return true;
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkbip())
        cout<<"Yes";
        else
        cout<<"No";
    return 0;
}