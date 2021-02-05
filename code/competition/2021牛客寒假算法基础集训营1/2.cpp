#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll k;
    cin>>k;
    vector<int> v;
    int ma=1;
    while(ma*ma<=k)
        ma++;
    ma--;
    int dis=k-ma*ma;
    string ans;
    int flag=0;
    int dis16=0;
    if(dis+ma*2>1e5+100){
        flag=1;
        dis16=dis/16;
        dis=dis%16;
    }
    ans.push_back('(');
    for(int i=1;i<=dis;i++)
        ans.push_back(')');
    if(flag){
        for(int i=1;i<=15;i++){
            ans.push_back('(');
        }
        for(int i=1;i<=dis16;i++)
            ans.push_back(')');
    }
    for(int i=1;i<=ma-1-flag*15;i++)
        ans.push_back('(');
    for(int i=1;i<=ma;i++)
        ans.push_back(')');
    cout<<ans<<endl;
}