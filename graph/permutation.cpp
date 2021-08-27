#include<bits/stdc++.h>
using namespace std;
int n;
void permute(vector<int>arr,vector<int>&vis,vector<int>&ds,vector<vector<int>>&ans)
{
    if(ds.size()==n)
    {ans.push_back(ds);return;}
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
            ds.push_back(arr[i]);
            vis[i]=true;
            permute(arr,vis,ds,ans);
            ds.pop_back();
            vis[i]=false;
        }
    }
}
int main(){
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int>vis(n,false);
    vector<int>ds;
    vector<vector<int>>ans;
    permute(a,vis,ds,ans);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}