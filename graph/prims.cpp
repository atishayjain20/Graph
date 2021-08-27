#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int key[n],parent[n];
    bool mstset[n];
    for(int i=0;i<n;i++)
    key[i]=INT_MAX,parent[i]=-1,mstset[i]=false;
    key[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int mini=INT_MAX,u;
        for(int v=0;v<n;v++)
        {
            if(mstset[v]==false&&mini>key[v])
            mini=key[v],u=v;
        }
        mstset[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(key[v]>wt&&mstset[v]==false)
            {
                key[v]=wt;
                parent[v]=u;
            }
        }
    }
    for(int i=1;i<n;i++)
        cout<<i<<"->"<<parent[i]<<endl;
}

//priority queue
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int key[n],parent[n];
    bool mstset[n];
    for(int i=0;i<n;i++)
    key[i]=INT_MAX,mstset[i]=false;
    key[0]=0;
    parent[0]=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    for(int i=0;i<n-1;i++)
    {
        int u=pq.top().second;
        pq.pop();
        mstset[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int wt=it.second;
            if(key[v]>wt&&mstset[v]==false)
            {
                key[v]=wt;
                parent[v]=u;
                pq.push({key[v],v});
            }
        }
    }
    for(int i=1;i<n;i++)
        cout<<i<<"->"<<parent[i]<<endl;
}