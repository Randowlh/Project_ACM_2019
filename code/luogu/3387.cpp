#include<bits/stdc++.h>
using namespace std;
const int maxn =110000;
int dfn[maxn],low[maxn];
bool flag[maxn];
vector<int> mp[maxn],mp2[maxn];
int cnt1,cnt2;
int n,m;
int u[maxn],v[maxn],belong[maxn];
int vl[maxn],vvl[maxn];
int dp[maxn];
stack<int> s;
void tarjan(int pos){
    dfn[pos]=low[pos]=++cnt1;
    s.push(pos);
    flag[pos]=1;
    for(int i=0;i<mp2[pos].size();i++){
        int to=mp2[pos][i];
        if(!dfn[to]){
            tarjan(to);
            low[pos]=min(low[pos],low[to]);
        }else if(flag[to])  
            low[pos]=min(low[pos],dfn[to]);
    }
    if(low[pos]==dfn[pos]){
        ++cnt2;
        while(s.top()!=pos){
            flag[s.top()]=0;
            belong[s.top()]=cnt2;
            vl[cnt2]+=vvl[s.top()];
            s.pop();
        }
        vl[cnt2]+=vvl[pos];
        flag[pos]=0;
        belong[pos]=cnt2;
        s.pop();
    }
}
int dfs(int pos){
    if(dp[pos])
        return dp[pos];
    int ans=0;
    for(int i=0;i<mp[pos].size();i++)
        ans=max(ans,dfs(mp[pos][i]));
    return dp[pos]=ans+vl[pos];
}
int main(){
    // freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   
        cin>>vvl[i];
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        mp2[u[i]].push_back(v[i]);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=m;i++){
        if(belong[v[i]]^belong[u[i]]){
            mp[belong[u[i]]].push_back(belong[v[i]]);
        }
    }
    int ans=0;
    for(int i=1;i<=cnt2;i++)
        ans=max(ans,dfs(i));
    cout<<ans<<endl;
}