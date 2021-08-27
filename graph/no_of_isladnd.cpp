#include<bits/stdc++.h>
using namespace std;
int n,m;
int adj[1000][1000];
void dfs(int r,int c){
    if(r<0||c<0||r>n||c>m||adj[r][c]==0)
    return;
    adj[r][c]=0;
    dfs(r,c-1);
    dfs(r,c+1);
    dfs(r+1,c);
    dfs(r-1,c);
}
int countislands(){
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(adj[i][j]==1){
                dfs(i,j);
                count++;
            }
        }
    }
    return count;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        cin>>adj[i][j];
    }
    cout<<countislands();
}