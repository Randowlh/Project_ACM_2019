#include<bits/stdc++.h>
using namespace std;
const int maxn=330;
int dp[maxn][maxn*20];
int s[maxn];
vector<int> mp[maxn];
int n,m;
void dfs(int pos){
    dp[pos][1]=s[pos];
    for(int i=0;i<mp[pos].size();i++){
        dfs(mp[pos][i]);
        for(int j=m+1;j>=0;j--)
            for(int k=0;k<j;k++)
                dp[pos][j]=max(dp[pos][j],dp[pos][j-k]+dp[mp[pos][i]][k]);
    }
}
int main(){
    // freopen("in.txt", "r", stdin);
    cin>>n>>m;
    int fa;
    for(int i=1;i<=n;i++){
        cin>>fa>>s[i];
        mp[fa].push_back(i);
    }
    dfs(0);
    cout<<dp[0][m+1]<<endl;
}