#include<bits/stdc++.h>
using namespace std;
const int mod=(0 ? 1000000007 : 998244353);
int dp[210000];
string tmp;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>tmp;
    int tot=1;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]*10+(tmp[i-1]-'0')*tot;
        dp[i]%=mod;
        tot+=dp[i];
        tot%=mod;
    }
    cout<<dp[n]<<endl;
}