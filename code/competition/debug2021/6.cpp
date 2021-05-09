#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
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
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 20000;
const int maxn = 11000;
struct edge{
   int to,nxt;
}eg[maxm];
int head[maxn];
int ecnt=0;
inline void add(int u,int v){
   eg[++ecnt].nxt=head[u];
   eg[ecnt].to=v;
   head[u]=ecnt;
}
inline void cl(int n){
   for(int i=0;i<=n;i++)
      head[i]=0;
   ecnt=0;
}
int dp[2][11000];
int dl[11000];
int flag[11000];
void dfs(int pos,int fa){
   flag[pos]=1;
   for(int i=head[pos];i;i=eg[i].nxt){
      int to=eg[i].to;
      if(to==fa)
         continue;
      dfs(to,pos);
      dp[0][pos]+=max(dp[1][to],dp[0][to]);
      dp[1][pos]+=dp[0][to];
   }
   dp[1][pos]+=dl[pos];
}
void work()
{
   int n,m;
   rd(n),rd(m);
   cl(n);
   for(int i=1;i<=n;i++) 
      rd(dl[i]),flag[i]=dp[1][i]=dp[0][i]=0;
   int u,v;
   for(int i=1;i<=m;i++){
      rd(u),rd(v);
      add(u,v);
      add(v,u);
   }
   int ans=0;
   for(int i=1;i<=n;i++){
      if(!flag[i]){
         dfs(i,-1);
         ans+=max(dp[1][i],dp[0][i]);
      }
   }
   cout<<ans<<endl;
} 
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
rd(t);
while (t--)
{
work();
}
return 0;
}