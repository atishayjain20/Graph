#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,fact=1;
    cin>>n>>k;
    vector<int>s;
    for(int i=1;i<n;i++)
    {
        fact=fact*i;
        s.push_back(i);
    }
    s.push_back(n);
    k=k-1;
    string ans="";
    while(true)
    {
        int idx=k/fact;
        ans+=to_string(s[idx]);
        s.erase(s.begin()+idx);
        if(s.size()==0)
        break;
        k=k%fact;
        fact=fact/s.size();
    }
    cout<<ans<<endl;
}