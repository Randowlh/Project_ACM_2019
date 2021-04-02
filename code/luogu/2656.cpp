#include<bits/stdc++.h>
using namespace std;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
const int maxn = 101000;
struct node{
    int nxt,to,w;
    double xs;
}eg[210000];
int head[101000];
int low[maxn],dfn[maxn];
bool flag[maxn];
int belong[maxn];
int ecnt=0;
stack<int> s;
void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].to=v;
    head[u]=ecnt;
}
int cnt1,cnt2;
void tarjan(int v){
    low[v]=dfn[v]=++cnt1;
    flag[v]=1;
    s.push(v);
    for(int i=head[v];i;i=eg[i].nxt){
        int to=eg[i].to;
        if(!dfn[to]){
            tarjan(to);
            MIN(low[v],low[to]);
        }else if(flag)
            MIN(low[v],dfn[to]);
    }
    if(low[v]==dfn[v]){
        ++cnt2;
        while(s.top()!=v){
            belong[s.top()]=cnt2;
            flag[s.top()]=0;
            s.pop();
        }
        belong[v]=cnt2;
        s.pop();
    }
}
int n,m;
int main(){
    rd(n),rd(m);
    int u,v,w;
    double xs;
    for(int i=1;i<=m;i++)
}