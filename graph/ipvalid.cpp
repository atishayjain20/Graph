#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    if(s[0]=='0' and s.size()>1)
    return false;
    return stoi(s)<=255;
}

vector<string> restoreIpAddresses(string A) {
    vector<string> ans;
    int n=A.size();
     for(int i=1;i<4 and i<n;i++){
         string firstp=A.substr(0,i);
         if(isvalid(firstp)){
             for(int j=1;j<4 && i+j<n;j++){
                 string secondp=A.substr(i,i+j);
                 if(isvalid(secondp)){
                    for(int k=1;k<4 && i+j+k<n;k++){
                        string thirdp=A.substr(i+j,i+j+k);
                        string fourthp=A.substr(i+j+k);
                        if(isvalid(thirdp) and isvalid(fourthp)){
                            ans.push_back(firstp+"."+secondp+"."+thirdp+"."+fourthp);
                        }
                    }
                 }
             }
         }
     }
     return ans;
}
int main()
{
	string s;
	cin>>s;
	vector<string>ans;
	ans=restoreIpAddresses(s);
	for(auto i:ans){
		cout<<i;
	}
	return 0;
}
