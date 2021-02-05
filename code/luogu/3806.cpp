#include <bits/stdc++.h>
using namespace std;
#define int long long
struct eg{
   int to,w,nxt;
}egs[11000];
int ecnt=0;
int head[11000];
int vis[11000];
int sz[11000];
int wt[11000];
int qr[1100];
int judge[(int)1e7+5];
int rt,sum;
int n,m,cnt;
void add(int u,int v,int w){
   egs[++ecnt].nxt=head[u];
   egs[ecnt].w=w;
   egs[ecnt].to
   =v;
   head[u]=ecnt;
}
void getrt(int u,int fa){
   sz[u]=1,wt[u]=0;
   for(int i=head[u];i;i=egs[i].nxt){
      int v=egs[i].to;
      if(vis[v]||fa==v)
         continue;
      getrt(v,u);
      sz[u]+=sz[v];
      wt[u]=max(wt[u],sz[v]);  
   }
   wt[u]=max(wt[u],sum-sz[u]);
   if(wt[u]<wt[rt])
      rt=u;
}
void solve(int u){
   queue<int> q;
   for(int i=head[u];i;i=egs[i].nxt){
      int v=egs[i].to;
      if(vis[v])
         continue;
      cnt=0;
      for(int i=1;i<=n;i++){
      }
   }
}
void div(int u){
   vis[u]=judge[0]=1;
   solve(u);
   for(int i=head[u];i;i=egs[i].nxt){
      int v=egs[i].to;
      if(vis[v])
         continue;
      wt[rt=0]=sum=sz[v];
      getrt(v,0);
      getrt(rt,0);
      div(rt);
   }
}
signed main(){
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   cin>>n>>m;
   int u,v,w;
   for(int i=1;i<=n-1;i++){
      cin>>u>>v>>w;
      add(u,v,w);
      add(v,u,w);
   }
   for(int i=1;i<=m;i++)
      cin>>qr[i];
   wt[0]=sum=n;
   getrt(1,0);
   getrt(rt,0);
   div(rt);
}