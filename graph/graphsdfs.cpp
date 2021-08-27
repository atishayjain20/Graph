#include<bits/stdc++.h>
using namespace std;
bool solve(int arr[][10],int i,int j,int n,int m){
	if(arr[i][j]==9)
	return true;
	if(i>n-1||j>m-1||i<0||j<0)
	return false;
	if(arr[i][j]==1)
	{
		if(solve(arr,i+1,j,n,m))
		return true;
		if(solve(arr,i,j+1,n,m))
		return true;
		if(solve(arr,i-1,j,n,m))
		return true;
		if(solve(arr,i,j-1,n,m))
		return true;
	}
	return false;
}
int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		cin>>arr[i][j];
	}
	cout<<solve(arr,0,0,n,m);
}
