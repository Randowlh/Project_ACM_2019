#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
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
#define pii(a,b) pair<a,b>
#define X first
#define Y second
#define lowbit(x) (x&-x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
// #define int long long
const ll llinf = 0x3f3f3f3f;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 210000;
const int maxn = 110000;
struct edge{
   int to,nxt;
}eg[maxm];
int head[maxn];
// vector<int> cnt[maxn];
int book[maxn];
int tdis[maxn];
int dis1[maxn],dis2[maxn];
bool flag[maxn];
int ecnt=0;
inline void add(int u,int v){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].to=v;
   head[u]=ecnt;
}
void cl(int n){
    ecnt=0;
    for(int i=1;i<=n;i++)
        head[i]=0;
}
int x,y,z;
int n,m;
int ans=0;
int ck(int pos,int step){
    int ans=0;
    for(int i=head[pos];i;i=eg[i].nxt){
        int to=eg[i].to;
        if(tdis[to]>step)
            ans+=ck(to,step+1);
    }
    return ans>0;
}
void dfs(int pos,int step){
    tdis[pos]=step;
    for(int i=head[pos];i;i=eg[i].nxt){
        int to=eg[i].to;
        if(!flag[to]){
            flag[to]=1;
            dfs(to,step+1);
        }
    }
}
void work()
{
    rd(n),rd(m);
    cl(n);
    for(int i=1;i<=n;i++){
        dis1[i]=dis2[i]=llinf; 
    }  
    rd(x),rd(y),rd(z);
    int u,v;
    for(int i=1;i<=m;i++){
        rd(u),rd(v);
        add(u,v);
        add(v,u);
    }
    queue<int> q;
    dis1[x]=1;
    q.push(x);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=head[t];i;i=eg[i].nxt){
            int to=eg[i].to;
            int now=dis1[t]+1;
            if(dis1[to]<now)
                continue;
            dis1[to]=now;
            q.push(to);
        }
    }
    dis2[y]=1;
    q.push(y);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        for(int i=head[t];i;i=eg[i].nxt){
            int to=eg[i].to;
            int now=dis2[t]+1;
            if(dis2[to]<now)
                continue;
            dis2[to]=now;
            q.push(to);
        }
    }
    if(dis1[z]==dis2[z]){
        if(dis1[z]==llinf){
            wt(2),pt('\n');
            return;
        }
        for(int i=1;i<=n;i++){
            if(dis1[i]>dis2[i])
                continue;
            for(int i=1;i<=n;i++)
                flag[i]=0;
            flag[i]=1;
            dfs(i,dis1[i]);
            if(!ck(y,1)){
                wt(1),pt('\n');
                return;
            }
        }
        wt(2),pt('\n');
    }else if(dis1[z]<dis2[z]){
        wt(1),pt('\n');
    }else{
        wt(3),pt('\n');
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
int t = 1;
rd(t);
// cin>>t;
while (t--)
{
work();
}
return 0;
}