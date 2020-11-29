#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
const int maxn=600;
const int maxm=maxn*maxn;
struct node{
    int to,nxt,w;
}eg[maxm];
int ecnt,cnt1,cnt2;
int dfn[maxn],low[maxn],head[maxn];
inline void add(int u,int v,int w){
    eg[++ecnt].nxt=head[u];
    eg[ecnt].to=v;
    eg[ecnt].w=w;
    head[u]=ecnt;
}
bool ins[maxn];
int main(){
    
}














































ck<int> s;
int main(){
    int n,m;
}