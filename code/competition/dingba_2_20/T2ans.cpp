#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510000;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
int n,m;
struct egs{
    int u,v,w;
}eg[550];
int d[maxn],pre[maxn];
int vis[maxn];
int tp=0;
int q[550];
int sum=0;
int mp[550][550];
inline int dis(int x,int y){
    if(x>y) swap(x,y);
    return min(pre[y]-pre[x],sum-(pre[y]-pre[x]));
}
signed main(){
    int u,v,w;
    int ans=0;
    rd(n),rd(m);
    for(int i=1;i<=n;i++)
        rd(d[i]),sum+=d[i];
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+d[i-1];
    for(int i=1;i<=m;i++){
        rd(eg[i].u),rd(eg[i].v),rd(eg[i].w);
        
    }
}