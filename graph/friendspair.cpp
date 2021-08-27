//how many ways in which n friends can remain single or paired up. 
#include<iostream>
using namespace std;
int pairs(int n)
{
    if(n==0||n==1||n==2)
    return n;
    return pairs(n-1)+pairs(n-2)*(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<pairs(n);
    return 0;
}