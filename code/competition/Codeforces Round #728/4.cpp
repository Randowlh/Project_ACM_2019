#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=210;
const int mod=1e9+7;
int dp[maxn][maxn];
int fa[maxn][20];
vector<int> mp[maxn];
int dep[maxn];
int inv(int a, int p)
{
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
void dfs(int pos,int faa,int step){
    dep[pos]=step;
    fa[pos][0]=faa;
    for(int i=1;i<=15;i++)
        fa[pos][i]=fa[fa[pos][i-1]][i-1];
    for(int i:mp[pos]){
        if(i==faa)
            continue;
        dfs(i,pos,step+1);
    }
}
int lca(int a,int b){
    if(dep[a]<dep[b])
        swap(a,b);
    for(int i=15;i>=0;i--)
        if(dep[fa[a][i]]>=dep[b])
        a=fa[a][i];
    // cout<<"a="<<a<<endl;
    if(a==b)
        return a; 
    for(int i=15;i>=0;i--)
        if(fa[a][i]!=fa[b][i])
            a=fa[a][i],b=fa[b][i];
    return fa[a][0];
}
signed main(){
    // freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    int v2=inv(2,mod);
    for(int i=0;i<=n;i++)
        dp[0][i]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod*v2%mod;
    //   for(int i=0;i<=n;i++){
        // for(int j=0;j<=n;j++)
            // cout<<dp[i][j]<<' ';
        // cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=n;i++){
        dfs(i,i,1);
        for(int j=1;j<=n;j++){
            // cout<<dep[j]<<' '<<fa[j][0]<<' '<<i<<' '<<fa[j][1]<<endl;
            for(int k=1;k<j;k++){
                int l=lca(j,k);
                // cout<<"k="<<k<<' '<<l<<' '<<j<<endl;
                ans+=dp[dep[j]-dep[l]][dep[k]-dep[l]];
                // cout<<dep[j]-dep[l]<<' '<<dep[k]-dep[l]<<endl;
                // cout<<"ans="<<ans<<endl;
                ans%=mod;
            }
        }
    }
    cout<<ans*inv(n,mod)%mod<<endl;
}