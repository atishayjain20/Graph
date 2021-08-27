#include<iostream>
using namespace std;
int knaps(int wt[4],int val[4],int weightin,int cap,int n)
{
    if(n==0)
    return 0;
    if(weightin>cap)
    return knaps(wt,val,weightin,cap,n-1);
    return max(knaps(wt,val,weightin,cap,n-1),knaps(wt,val,weightin+wt[n-1],cap-wt[n],n-1)+val[n-1]);
}
int main()
{
    int wt[]={100,50,75,125};
    int val[]={100,10,75,125};
    int cap=150;
    cout<<knaps(wt,val,0,cap,4);
}