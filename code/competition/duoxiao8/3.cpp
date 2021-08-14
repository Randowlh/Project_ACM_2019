#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
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
namespace FastIO
{
char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
int p, p3 = -1;
void read() {}
void print() {}
inline int getc()
{
return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
}
inline void flush()
{
fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth)
{
int f = 0;x = 0;char ch = getc();
while (!isdigit(ch)){if (ch == '-')f = 1;ch = getc();}
while (isdigit(ch)){x = x * 10 + ch - 48;ch = getc();}
x = f ? -x : x;read(oth...);
}
template <typename T, typename... T2>
inline void print(T x, T2... oth)
{
if (p3 > 1 << 20)flush();
if (x < 0)buf2[++p3] = 45, x = -x;
do{a[++p] = x % 10 + 48;}while (x /= 10);
do{buf2[++p3] = a[p];}while (--p);
buf2[++p3] = hh;
print(oth...);
}
} // namespace FastIO
#define read FastIO::read
#define print FastIO::print
#define flush FastIO::flush
#define spt fixed<<setprecision
#define endll '\n'
#define mul(a,b,mod) (__int128)(a)*(b)%(mod) 
#define pii(a,b) pair<a,b>
#define pow powmod
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
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 110000;
int date[maxn];
int add[maxn<<2];
int dc[maxn<<2];
int seg[maxn<<2];
int cnt[maxn<<2];
int lazy1[maxn<<2],lazy2[maxn<<2];
int er[maxn];
void pushup(int pos){
    cnt[pos]=cnt[lson(pos)]+cnt[rson(pos)];
    seg[pos]=(seg[lson(pos)]+seg[rson(pos)])%mod;
    add[pos]=add[lson(pos)]+add[rson(pos)];
    return;
}
void pushdown(int pos){
    if(lazy1[pos]){
        int t=(er[lazy1[pos]]-1+mod)%mod;
        seg[lson(pos)]+=(er[add[lson(pos)]]*t)%mod;
        seg[lson(pos)]%=mod;
        add[lson(pos)]+=lazy1[pos];
        lazy1[lson(pos)]+=lazy1[pos];
        seg[rson(pos)]+=(er[add[rson(pos)]]*t)%mod;
        seg[rson(pos)]%=mod;
        add[rson(pos)]+=lazy1[pos];
        lazy1[rson(pos)]+=lazy1[pos];
        lazy1[pos]=0;
    }
    if(lazy2[pos]){
        int t=(er[lazy2[pos]]-1+mod)%mod;
        seg[lson(pos)]+=mod-(er[dc[lson(pos)]]*t)%mod;
        seg[lson(pos)]%=mod;
        dc[lson(pos)]+=lazy2[pos];
        lazy2[lson(pos)]+=lazy2[pos];
        seg[rson(pos)]+=mod-(er[dc[rson(pos)]]*t)%mod;
        seg[rson(pos)]%=mod;
        dc[rson(pos)]+=lazy2[pos];
        lazy2[rson(pos)]+=lazy2[pos];
        lazy2[pos]=0;
    }
}
void update(int pos,int l,int r,int ql,int qr,int flag){
    if(ql<=l&&qr>=r&&(!(!flag&&cnt[pos]))){
        if(flag){
            lazy2[pos]++;
            seg[pos]=(seg[pos]+er[add[pos]])%mod;
            add[pos]++;
        }else{
            lazy1[pos]++;
            seg[pos]=((seg[pos]-er[dc[pos]])%mod+mod)%mod;
            dc[pos]++;
            if(add[pos]==dc[pos])
                add[pos]=dc[pos]=seg[pos]=0;
        }
        return;
    }
    else
    if(l==r){
        cnt[pos]--;
        int t=lowbit(date[l]);
        seg[pos]=(seg[pos]-t+mod)%mod;
        if(cnt[pos]==0)
            dc[pos]=t<<1;
        if(add[pos]==dc[pos])
            add[pos]=dc[pos]=seg[pos]=0;
        return;
    }
    pushdown(pos);
    int mid=(l+r)>>1;
    if(ql<=mid)
        update(lson(pos),l,mid,ql,qr,flag);
    if(qr>mid)
        update(rson(pos),mid+1,r,ql,qr,flag);
    pushup(pos);
}
void build(int pos,int l,int r){
    lazy1[pos]=lazy2[pos]=0;
    if(l==r){
        seg[pos]=date[l];
        // cout<<"seg[pos]="<<seg[pos]<<endl;
        int ct=0;
        int a=1;
        int ct2=0;
        while(a<=date[l]){
            if(a&date[l])
                ct2++;
            a<<=1;
            ct++;
        }
        add[pos]=ct;
        cnt[pos]=ct2;
        return ;
    }
    int mid=l+r>>1;
    build(lson(pos),l,mid);
    build(rson(pos),mid+1,r);
    pushup(pos);
}
int query(int pos,int l,int r,int ql,int qr){
    // cout<<"l="<<l<<' '<<r<<' '<<seg[pos]<<endl;
    if(l>=ql&&r<=qr)
        return seg[pos];
    int mid=(l+r)>>1;
    int ans=0;
    if(ql<=mid)
        ans+=query(lson(pos),l,mid,ql,qr);
    if(qr>mid)  
        ans+=query(rson(pos),mid+1,r,ql,qr);
    ans%=mod;
    return ans;
}
void work()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    build(1,1,n);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int opt,l,r;
        cin>>opt>>l>>r;
        // cout<<"opt="<<opt<<endll;
        if(opt==2){
            update(1,1,n,l,r,0);
        }else if(opt==3){
            update(1,1,n,l,r,1);
        }else{
            // cout<<l<<' '<<r<<endl;
            cout<<query(1,1,n,l,r)<<endll;
        }
    }
}
signed main()
{
    er[0]=1;
    for(int i=1;i<=100010;i++)
        er[i]=er[i-1]*2%mod;
    er[0]=0;
   #ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}