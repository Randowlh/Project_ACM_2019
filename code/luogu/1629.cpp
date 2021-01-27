#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
struct edge{
    int w,to,nxt;
}egs[210000][2];
int n,dis[2][1100],head[1100][2],tot[2];
void add(int u,int v,int w,int flag){
    egs[++tot[flag]][flag].nxt=head[u][flag];
    egs[tot[flag]][flag].to=v;
    egs[tot[flag]][flag].w=w;
    head[u][flag]=tot[flag];
}
void dij(int s,int f){
    for(int i=1;i<=n;i++)
        dis[f][i]=inf;
    dis[f][s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0LL,s));
    while(!q.empty()){
        pair<int,int> t=q.top();
        q.pop();
        if(t.first>dis[f][t.second])
            continue;
        for(int i=head[t.second][f];i;i = egs[i][f].nxt){
            int to=egs[i][f].to;
            if(dis[f][t.second]+egs[i][f].w<dis[f][to]){
                dis[f][to]=dis[f][t.second]+egs[i][f].w;
                q.push(make_pair(dis[f][to],to));
            }
        }
    }
}
int main(){
    int m;
    rd(n),rd(m);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        add(u,v,w,0);
        add(v,u,w,1);
    }
    for(int i=0;i<=1;i++)
        dij(1,i);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans+=dis[1][i]+dis[0][i];
    cout<<ans<<endl;
}