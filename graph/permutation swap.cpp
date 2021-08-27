//permutation with swap
#include<bits/stdc++.h>
using namespace std;
void permute(vector<int>arr,vector<vector<int>>&ans,int idx)
{
    if(idx==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for(int i=idx;i<arr.size();i++)
    {
        swap(arr[idx],arr[i]);
        permute(arr,ans,idx+1);
        swap(arr[i],arr[idx]);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>ans;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    permute(arr,ans,0);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}