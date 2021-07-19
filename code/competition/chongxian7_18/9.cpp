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
const int maxn = 2010000;
struct seg{
    int seg[maxn<<2];
    int lazy[maxn<<2];
    inline void pushdown(int pos){
        if(lazy[pos]){
            seg[lson(pos)]+=lazy[pos];
            seg[rson(pos)]+=lazy[pos];
            lazy[lson(pos)]+=lazy[pos];
            lazy[rson(pos)]+=lazy[pos];
            lazy[pos]=0;
        }
    }
    void build(int pos,int l,int r){
        if(l==r){
            seg[pos]=l;
            return;
        }
        lazy[pos]=0;
        int mid=l + r >> 1;
        build(lson(pos),l,mid);
        build(rson(pos),mid+1,r);
    }
    void update(int pos,int l,int r,int ql,int qr,int v){
        if(l>r)
            return;
        if(l>=ql&&r<=qr){
            lazy[pos]+=v;
            seg[pos]+=v;
            return;
        }
        pushdown(pos);
        int mid=l+r>>1;
        if(ql<=mid)
            update(lson(pos),l,mid,ql,qr,v);
        if(qr>=mid+1)
            update(rson(pos),mid+1,r,ql,qr,v);
    }
    int qr(int pos,int l,int r,int x){
        if(l==r)
            return seg[pos];
        int mid=l + r >> 1;
        pushdown(pos);
        if(x<=mid)
            return qr(lson(pos),l,mid,x);
        else return qr(rson(pos),mid+1,r,x);
    }
};
string a,b;
void work()
{
    cin>>a>>b;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}