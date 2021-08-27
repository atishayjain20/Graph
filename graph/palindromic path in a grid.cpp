//palindromic path in a grid
#include<bits/stdc++.h>
using namespace std;
int n,m;
int dp[4][5][4][5];
int a[3][4];
int palipath(int i,int j,int k,int l)
{
    if(i>k||j>l||a[i][j]!=a[k][l])
    return 0;
    if(abs((k-i)+(l-j))==1)return 1;
    if(dp[i][j][k][l]!=-1) return dp[i][j][k][l];
    return dp[i][j][k][l]=palipath(i+1,j,k-1,l)+
    palipath(i,j+1,k-1,l)+
    palipath(i+1,j,k,l-1)+
    palipath(i,j+1,k,l-1);
}
int main(){
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        cin>>a[i][j];
    }
    memset(dp,-1,sizeof(dp));
    palipath(0,0,2,3);
    cout<<dp[0][0][2][3];
    return 0;
}