#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int maxm= 2000100;
const int maxn = 500100;
int fa[500100],jian[500100],vl[500100];
inline int find(int x){
    if(fa[x]==x) return x;
    else return fa[x]=find(fa[x]);
}
pair<int,int> date[500100];
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    if(l!=r)
        fa[l]=r;
}
struct eg{
    int fr,to;
    bool operator<(eg a){
        if(min(vl[fr],vl[to])==min(vl[a.fr],vl[a.to])){
            return max(vl[fr],vl[to])>max(vl[a.fr],vl[a.to]);
        }else return min(vl[fr],vl[to])>min(vl[a.fr],vl[a.to]);
    }
}egs[1000100];
int ans=0;
void work()
{
    int n,m;
    rd(n),rd(m);
    for(int i=1;i<=n;i++){
        rd(date[i].first);
        vl[i]=date[i].first;
        date[i].second=i;
        fa[i]=i;
    }
    sort(date+1,date+n+1,greater<pair<int,int> >());
    int u,v;
    for(int i=1;i<=m;i++)
        rd(egs[i].fr),rd(egs[i].to);
    sort(egs+1,egs+m+1);
    for(int i=1;i<=m;i++){
        int a=find(egs[i].fr);
        int b=find(egs[i].to);
        if(a==b)
            continue;
        if(vl[a]<vl[b])
            swap(a,b);
        ans+=vl[a]-vl[b];
        vl[a]=vl[b];
        merge(a,b);
    }
    for(int i=1;i<=n;i++){
        ans+=vl[find(i)];
        vl[find(i)]=0;
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