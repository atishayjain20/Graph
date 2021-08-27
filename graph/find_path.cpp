#include<bits/stdc++.h>
using namespace std;
bool visited[1000][1000];
bool blocked[1000][1000];
int height,width;
int adj[1000][1000];
bool valid(int x,int y){
    if(x<0||y<0||x>=height||y>=width||visited[x][y]||blocked[x][y]){
        return false;
    }
    return true;
}
bool find_path(int x,int y,int ex,int ey){
    if(!valid(x,y))
    return false;
    visited[x][y]=1;
    if(x==ex && y==ey)
    return true;
    bool found=false;
    if(find_path(x+1,y,ex,ey))found=true;
    if(find_path(x,y+1,ex,ey))found=true;
    if(find_path(x-1,y,ex,ey))found=true;
    if(find_path(x,y-1,ex,ey))found=true;
    return found;
}
int main(){
    int n,m;
    cin>>height>>width;
    n=height;m=width;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>adj[i][j];
            if(adj[i][j]==0)
            blocked[i][j]=true;
        }
    }
    cout<<find_path(0,0,3,3)<<endl;
    return 0;
}