#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
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
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
const int maxm= 410000;
const int maxn = 210000;
struct edge{
   int w,to,nxt;
}eg[maxm][2];
int head[maxn][2];
int ecnt=0;
inline void add(int u,int v,int w,int fl){
    // if(fl)
    //     cout<<u<<"->"<<v<<endl;
   eg[++ecnt][fl].nxt=head[u][fl];
   eg[ecnt][fl].w=w;
   eg[ecnt][fl].to=v;
   head[u][fl]=ecnt;
}
int FA[maxn];
int cnt1=0;
int fa[maxn][25],cd[maxn][25];
int dis[maxn];
int dfn[maxn],low[maxn];
int dep[maxn];
int sum[maxn];
int tail;
bool book[maxn];
void jiadian(int pos,int to,int w){
    sum[++tail]=dis[to]-dis[pos]+w;
    add(pos,tail,0,1);
    add(tail,pos,0,1);
    int now=to;
    while(now!=pos){
        // cout<<"now="<<now<<endl;
        int ddis=min(dis[now]-dis[pos],sum[tail]-(dis[now]-dis[pos]));
        // cout<<"ddis="<<ddis<<endl;
        add(now,tail,ddis,1);
        add(tail,now,ddis,1);
        book[now]=(ddis==(dis[now]-dis[pos]));
        now=fa[now][0];
    }
}
void tarjan(int pos,int f){
    dfn[pos]=low[pos]=++cnt1;
    fa[pos][0]=f;
    for(int i=head[pos][0];i;i=eg[i][0].nxt){
        int to=eg[i][0].to,w=eg[i][0].w;
        if(!dfn[to]){
            dis[to]=dis[pos]+w;
            tarjan(to,pos);
            MIN(low[pos],low[to]);
        }else if(to!=f)
            MIN(low[pos],dfn[to]);
        if(dfn[pos]<low[to])
            add(pos,to,w,1),add(to,pos,w,1);
    }
    for(int i=head[pos][0];i;i=eg[i][0].nxt){
        int to=eg[i][0].to,w=eg[i][0].w;
        if(fa[to][0]!=pos&&dfn[to]>dfn[pos])
            jiadian(pos,to,w);
    }
}
void dfs(int pos,int f){
    dep[pos]=dep[f]+1;
    for(int i=1;i<=20;i++)
        fa[pos][i]=fa[fa[pos][i-1]][i-1],cd[pos][i]=cd[fa[pos][i-1]][i-1]+cd[pos][i-1];
    for(int i=head[pos][1];i;i=eg[i][1].nxt){
        int to=eg[i][1].to,w=eg[i][1].w;
        if(to==f)
            continue;
        fa[to][0]=pos;
        cd[to][0]=w;
        dfs(to,pos);
    }
}
int n,m,q;
int getans(int a,int b){
    int ans=0;
    if(dep[a]<dep[b]) 
        swap(a,b);
    for(int i=20;i>=0;i--)
        if(dep[fa[a][i]]>=dep[b]){
            ans+=cd[a][i];
            a=fa[a][i];
        }
    if(a==b)
        return ans;
    for(int i=20;i>=0;i--)
        if(fa[a][i]!=fa[b][i]){
            ans+=cd[a][i]+cd[b][i];
            a=fa[a][i];
            b=fa[b][i];
        }
    if(fa[a][0]<=n)
        return ans+cd[a][0]+cd[b][0];
    int dis;
    if(book[a]!=book[b])
        dis=cd[a][0]+cd[b][0];
    else dis=abs(cd[a][0]-cd[b][0]);
    return ans+min(dis,sum[fa[a][0]]-dis);
}
void work()
{
    rd(n),rd(m),rd(q);
    int cnt=n;   
    int u,v,w;
    for(int i=1;i<=m;i++){
        // cin>>u>>v>>w;
        rd(u),rd(v),rd(w);
        add(u,v,w,0);
        add(v,u,w,0);
    }
    tail=n;
    tarjan(1,-1);
    // cout<<"dadasd"<<endl;
    fa[1][0]=1;
    dep[0]=-1;
    for(int i=0;i<20;i++)
        fa[1][i]=1;
    dfs(1,0);
    // for(int i=1;i<=tail;i++){
    //     cout<<"fa["<<i<<"]="<<fa[i][0]<<endl;
    // }
    for(int i=1;i<=q;i++){
        int a,b;
        // cin>>a>>b;
        rd(a),rd(b);
        wt(getans(a,b)),putchar('\n');
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio( false);
//cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}