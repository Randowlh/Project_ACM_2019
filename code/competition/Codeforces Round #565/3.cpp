#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int tmp;
    vector<int> v;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    map<int,int> M;
    int ans=0;

    for(int i=1;i<=n;i++){
        M[v[i-1]]++;
    }
    ans=0x7FFFFFFF;
    for(auto i=M.begin();i!=M.end();i++){
        ans=min(ans,i->second);
    }
    if(M.size()<6)
        ans=0;
    cout<<n-ans*6<<endl;
}