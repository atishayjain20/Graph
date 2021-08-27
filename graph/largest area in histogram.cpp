#include<iostream>
using namespace std;
int n;
int largestarea(int arr[])
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int minh=arr[i];//6
        for(int j=i;j<n;j++)
        {
            minh=min(minh,arr[j]);//2
            ans=max(ans,minh*(j-i+1));
        }
    }
    return ans;
}
int main(){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<largestarea(arr);
    return 0;
}

//stack
int getmaxarea(){
    stack<int>s;
    int i=0;
    while(i<n){
    if(s.empty()||hi[s.top()]<=hi[i])
    s.push(i++);
    else{
        tp=s.top();
        s.pop();
        area=hi[tp]*(s.empty()?1:i-s.top-1);
        max_area=max(max_area,area);
    }
    while(s.empty()==false){
        tp=s.top();
        s.pop();
        area=hi[tp]*(s.empty()?1:i-s.top-1);
        max_area=max(max_area,area);
    }
    return max_area;
    }
}