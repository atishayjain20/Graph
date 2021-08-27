//same for painters partition
#include<bits/stdc++.h>
using namespace std;
bool ispossible(int arr[],int m,int n,int min)
{
    int studentsrequired=1,sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>min)
        return false;
        if(arr[i]+sum>min)
        {
            studentsrequired++;
            sum=arr[i];
            if(studentsrequired>m)
            return false;
        }
        else
        sum+=arr[i];
    }
    return true;
}
int minimumpage(int arr[],int m,int n){
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    int end=sum;
    int start=0;
    int minpages=INT_MAX;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(ispossible(arr,m,n,mid)){
            end=mid-1;
            minpages=min(minpages,mid);
        }
        else{
            start=mid+1;
        }
    }
    return minpages;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int m;cin>>m;
    cout<<minimumpage(arr,m,n);
    return 0;
}