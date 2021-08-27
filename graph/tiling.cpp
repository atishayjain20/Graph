//2*n board and tile of 2*1 number of ways to tile board
#include<iostream>
using namespace std;
int countways(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return countways(n-1)+countways(n-2);
}
int main()
{
    int n;
    cin>>n;
    if(n==2)
    return 2;
    else cout<<countways(n);
    return 0;
}