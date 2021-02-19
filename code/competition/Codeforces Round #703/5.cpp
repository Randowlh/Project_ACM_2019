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
// const int maxm= 101000000;
const int maxn = 110000;
vector<pair<int,int>> mp[110000];
map<int,int> M[110000];
int n;
int dis[maxn];
void dij(int a){
   for(int i=1;i<=n;i++)
      dis[i]=llinf;
   dis[a]=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;
   q.push(pair<int,int>(0,a));
   while(!q.empty()){
      pair<int,int> t=q.top();
      q.pop();
      if(dis[t.second]<t.first)
         continue;
        for(auto i=M[t.second].begin();i!=M[t.second].end();i++){
            int to=i->first;
            int w=i->second;
            // cout<<"to"<<to<<" w"<<w<<endl;
            if(w+dis[t.second]<dis[to]){
                dis[to]=w+dis[t.second];
                q.push(make_pair(dis[to],to));
            }
        }
    }
}
void ck(int fr,int tot,int now,int step){
    if(step==3){
        if(M[fr].count(now)==0)
            M[fr][now]=tot*tot;
        else M[fr][now]=min(M[fr][now],tot*tot);
        return;
    }
    for(int i=0;i<mp[now].size();i++){
        int to=mp[now][i].first;
        if(to==fr)
            continue;
        ck(fr,tot+mp[now][i].second,to,step+1);
    }
}
void work()
{
    int m;
    rd(n),rd(m);
    int u,v,w;
    for(int i=1;i<=m;i++){
        rd(u),rd(v),rd(w);
        mp[u].push_back(make_pair(v,w));
        mp[v].push_back(make_pair(u,w));
    }
    for(int i=1;i<=n;i++)
        ck(i,0,i,1);
    dij(1);
    for(int i=1;i<=n;i++){
        if(dis[i]==llinf)
            dis[i]=-1;
        wt(dis[i]),pt(' ');
    }
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