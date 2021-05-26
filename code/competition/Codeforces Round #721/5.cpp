#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
// #define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn =41000;
int lazy[110][maxn<<2];
int seg[110][maxn<<2];
int date[maxn];
int n,k;
int now[maxn],pre[maxn];
inline void pushup(int lr,int pos){
    seg[lr][pos]=min(seg[lr][lson(pos)],seg[lr][rson(pos)]);
}
inline void pushdown(int lr,int pos){
    if(lazy[lr][pos]){
        int t=lazy[lr][pos];
        lazy[lr][pos]=0;
        lazy[lr][lson(pos)]+=t;
        seg[lr][lson(pos)]+=t;
        lazy[lr][rson(pos)]+=t;
        seg[lr][rson(pos)]+=t;
    }
}
void build(int lr,int pos,int l,int r){
    if(l==r){
        seg[lr][pos]=1e9;
        return;
    }
    int mid=(l+r)>>1;
    build(lr,lson(pos),l,mid);
    build(lr,rson(pos),mid+1,r);
    pushup(lr,pos);
}
void update(int lr,int pos,int l,int r,int ql,int qr,int v){
    if(ql<=l&&qr>=r){
        lazy[lr][pos]+=v;
        seg[lr][pos]+=v;
        return;
    }
    pushdown(lr,pos);
    int mid=(l+r)>>1;
    if(ql<=mid)
        update(lr,lson(pos),l,mid,ql,qr,v);
    if(qr>mid)
        update(lr,rson(pos),mid+1,r,ql,qr,v);
    pushup(lr,pos);
}
int query(int lr,int pos,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r)
        return seg[lr][pos];
    int ans=1e9;
    int mid=(l+r)>>1;
    pushdown(lr,pos);
    if(ql<=mid)
        MIN(ans,query(lr,lson(pos),l,mid,ql,qr));
    if(qr>mid)
        MIN(ans,query(lr,rson(pos),mid+1,r,ql,qr));
    return ans;
}
void work()
{
    rd(n);rd(k);
    for(int i=1;i<=n;i++)
        rd(date[i]);
    for(int i=1;i<=n;i++){
        if(now[date[i]])
            pre[i]=now[date[i]];
        else pre[i]=i;
        now[date[i]]=i;
    }
    for(int i=0;i<=k;i++)
        build(i,1,0,n);
    update(0,1,0,n,0,0,-1e9);
    for(int j=1;j<=n;j++)
    for(int i=1;i<=min(j,k);i++)
        {
            if (j!=pre[j])
                update(i-1,1,0,n,0,pre[j]-1,j-pre[j]);
            update(i,1,0,n,j,j,query(i-1,1,0,n,0,j-1)-1e9);
        }
    wt(query(k,1,0,n,n,n)),pt('\n');
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
// std::ios::sync_with_stdio(false);
// cin.tie(NULL);
int t = 1;
// cin>>t;
while (t--)
{
work();
}
return 0;
}