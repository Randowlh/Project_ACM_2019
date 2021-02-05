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
const int maxm= 1;
const int maxn = 510000;
int seg[2][210000<<2];
bool xq[2][210000<<2];
int n;
int cnt[2];
inline void pushup(int T,int pos){
    seg[T][pos]=seg[T][lson(pos)]+seg[T][rson(pos)];
}
void build(int pos,int l,int r){
    if(l==r){
        seg[0][pos]=l;
        seg[1][pos]=(r-1)*n+1;
        return;
    }
    int mid=(l+r)>>1;
    build(lson(pos),l,mid);
    build(rson(pos),mid+1,r);
    pushup(1,pos);
    pushup(0,pos);
    return;
}
void update(int T,int pos,int l,int r,int x){
    if(l==r){
        seg[T][pos]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)
        update(T,lson(pos),l,mid,x);
    else update(T,rson(pos),mid+1,r,x);
    pushup(T,pos);
}
void work()
{
    int m;
    rd(n),rd(m);
    cnt[1]=cnt[0]=n;
    build(1,1,n);
    int k,p;
    // cout<<seg[1][1]<<endl;
    for(int i=1;i<=m;i++){
        rd(k),rd(p);
        if(xq[k][p]){
            wt(0),pt('\n');
            continue;
        }
        int now=seg[k][1];
        xq[k][p]=1;
        if(now==0){
            wt(0),pt('\n');
            continue;
        }
        // cout<<"now="<<now<<' '<<k<<' '<<p<<endl;
        if(k==0){
            now+=cnt[0]*(p-1)*n;
        }else{
            now+=cnt[1]*(p-1);
        }
        cnt[k^1]--;
        // cout<<seg[1][1]<<endl;
        update(k^1,1,1,n,p);
        // cout<<seg[1][1]<<endl;
        wt(now),pt('\n');
    }
    return ;
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