#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
const int llinf= 4223372036854775807;
const int maxn=110000;
const int maxm=510000;
pair<int,int> heap[maxn<<2];
int tail=0;
void insert(pair<int,int> a){
   heap[++tail]=a;
   int now=tail-1;
   while(now>1){
      int to=now/2;
      if(heap[to]>heap[now]){
         swap(heap[to],heap[now]);
         now=to;
      }else break;
   }
}
void pushdown(int pos){
   int lag=pos;
   if(lson(pos)<=tail&&heap[lson(pos)]<heap[pos])
      lag=lson(pos);
   if(rson(pos)<=tail&&heap[rson(pos)]<heap[lag])
      lag=rson(pos);
   if(lag!=pos){
      swap(heap[pos],heap[lag]);
      pushdown(lag);
   }
}
void pop(){
   swap(heap[1],heap[tail]);
   tail--;
   pushdown(1);
}
struct edge{
   int w,to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v,int w){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].w=w;
   eg[ecnt].to=v;
   head[u]=ecnt;
}
int n,m,s;
int dis[maxn];
void dij(int a){
   for(int i=1;i<=n;i++)
      dis[i]=llinf;
   dis[a]=0;
   insert(pair<int,int>(0,a));
   while(tail){
      pair<int,int> t=heap[1];
      pop();
      if(dis[t.second]<t.first)
         continue;
        for(int i=head[t.second];i;i = eg[i].nxt){
            int& to=eg[i].to;
            if(eg[i].w+dis[t.second]<dis[to]){
                dis[to]=eg[i].w+dis[t.second];
                insert(make_pair(dis[to],to));
            }
        }
    }
}
signed main(){
    cin>>n>>m>>s;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dij(s);
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<' ';
    cout<<endl;
}