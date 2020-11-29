// #include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
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
const int maxm= 101000;
const int maxn = 11000;
struct edge{
    int to,nxt;
}eg[2][maxm];
int ecnt[2];
int dfn[maxn],low[maxn],vl[maxn],head[2][maxn],belong[maxn],du[maxn],sz[maxn];
bool ins[maxn];
void add(int u,int v,int flag){
   eg[flag][++ecnt[flag]].nxt=head[flag][u];
   eg[flag][ecnt[flag]].to=v;
   head[flag][u]=ecnt[flag];
}
stack<int> s;
int cnt1,cnt2;
void tarjan(int now){
   dfn[now]=low[now]=++cnt1;
   ins[now]=1;
   s.push(now);
   // cout<<"nn"<<now<<endl;
   for(int i=head[0][now];i;i=eg[0][i].nxt){
      int to=eg[0][i].to;
      if(!dfn[to]){
         tarjan(to);
         MIN(low[now],low[to]);
      }else if(ins[to]){
         MIN(low[now],dfn[to]);
      }
   }
   if(dfn[now]==low[now]){
      cnt2++;
      vl[cnt2]=0;
      while(s.top()!=now){
         vl[cnt2]++;
         belong[s.top()]=cnt2;
         ins[s.top()]=0;
         s.pop();
      }
      vl[cnt2]++;
      belong[s.top()]=cnt2;
      ins[s.top()]=0;
      s.pop();
      sz[cnt2]=vl[cnt2];
   }
}
int n,m;
void work()
{
   rd(n),rd(m);
   int u,v;
   for(int i=0;i<m;i++){
      rd(u),rd(v);
      add(u,v,0);
   }
   for(int i=1;i<=n;i++){
      if(!dfn[i])
         tarjan(i);
   }
   for(int i=1;i<=n;i++)
      for(int j=head[0][i];j;j=eg[0][j].nxt)
         if(belong[i]!=belong[eg[0][j].to])
            add(belong[i],belong[eg[0][j].to],1),du[belong[eg[0][j].to]]++;;
   queue<int> q;
   for(int i=1;i<=cnt2;i++){
      if(!du[i])
         q.push(i);
   }
   // cout<<"dsadsa"<<endl;
   while(!q.empty()){
      int t=q.front();
      q.pop();
      for(int i=head[1][t];i;i=eg[1][i].nxt){
         int to=eg[1][i].to;
         sz[to]+=sz[t];
         du[to]--;
         if(!du[to])
            q.push(to);
      }
   }
   int ans=0;
   for(int i=1;i<=cnt2;i++){
      if(sz[i]==n){
         ans+=vl[i];         
      }
   }
   wt(ans),pt('\n');
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}