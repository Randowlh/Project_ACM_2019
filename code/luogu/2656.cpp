#include<bits/stdc++.h>
using namespace std;
const int maxn=210000;
vector<pair<int,int>> mp[maxn];
vector<int> mp2[maxn];
int low[maxn],dfn[maxn],belong[maxn];
int u[maxn],v[maxn];
int val[maxn],tval[maxn],vl[maxn];
int n,m;
int cnt1,cnt2;
int flag[maxn];
stack<int> s;
int calc(int val,double xs){
    int ans=val;
    int t=0;
    while(t=int(val*xs)){
        ans+=t;
        val*=xs;
    }
    return ans;
}
void tarjan(int pos){
    s.push(pos);
    dfn[pos]=low[pos]=++cnt1;
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
            s.pop();
        }
        belong[pos]=cnt2;
        flag[pos]=0;
        s.pop();
    }
}
int dfs(int pos){
    int ans=0;
    for(int i=0;i<mp[pos].size();i++){
        int to=mp[pos][i].first;
        int jia=mp[pos][i].second;
        int t=dfs(to)+jia;
        ans=max(t,ans);
    }
    ans+=vl[pos];
    return ans;
}
int main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i];
        mp2[u[i]].push_back(v[i]);
        double tt;
        cin>>val[i]>>tt;
        tval[i]=calc(val[i],tt);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    for(int i=1;i<=m;i++){
        if(belong[u[i]]==belong[v[i]])
            vl[belong[u[i]]]+=tval[i];
        else
            mp[belong[u[i]]].push_back(make_pair(belong[v[i]],val[i]));
    }
    int s;
    cin>>s;
    cout<<dfs(belong[s])<<endl;
}