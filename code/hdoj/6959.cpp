#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
#define MIN(x,y) if((y)>(x))(x)=(y)
#define MAX(x,y) if((y)>(x))(x)=(y)
// namespace FastIO
// {
// char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf, hh = '\n';
// int p, p3 = -1;
// void read() {}
// void print() {}
// inline int getc()
// {
//     return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
//     }
//     inline void flush()
//     {
//     fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
//     }
//     template <typename T, typename... T2>
//     inline void read(T &x, T2 &... oth)
//     {
//     int f = 0;x = 0;char ch = getc();
//     while (!isdigit(ch)){if (ch == '-')f = 1;ch = getc();}
//     while (isdigit(ch)){x = x * 10 + ch - 48;ch = getc();}
//     x = f ? -x : x;read(oth...);
//     }
//     template <typename T, typename... T2>
//     inline void print(T x, T2... oth)
//     {
//     if (p3 > 1 << 20)flush();
//     if (x < 0)buf2[++p3] = 45, x = -x;
//     do{a[++p] = x % 10 + 48;}while (x /= 10);
//     do{buf2[++p3] = a[p];}while (--p);
//     buf2[++p3] = hh;
//     print(oth...);
// }
// } // namespace FastIO
#define read FastIO::read
#define print FastIO::print
#define flush FastIO::flush
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
// #define int long long
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
int ans[maxn];
int n,m;
int blk=sqrt(100000);
// int blk2=;
struct qs{
    int l,r;
    int yl,yr;
    int num;
    qs(){}
    qs(int a,int b,int c,int d,int n):l(a),r(b),yl(c),yr(d),num(n){}
    bool operator<(qs a){
        if(l/blk==a.l/blk)
            return r<a.r;
        else return l<a.l;
    }
}qr[maxn];
int cnt[maxn];
int sum[maxn];
int calc(int x){
        int now=0;
        for (int i=0;i<x/blk;i++) now+=sum[i];
        for (int i=(x/blk)*blk;i<=x;i++) now+=(cnt[i]>=1);
        return now;
}
void move(int pos,int flag){
    if(flag){
        if(!cnt[date[pos]])
            sum[date[pos]/blk]++;
        cnt[date[pos]]++;
    }else{
        if(cnt[date[pos]]==1)
            sum[date[pos]/blk]--;
        cnt[date[pos]]--;
    }
}
void work()
{   
    int x0,y0,x1,y1;
    cin>>n>>m;
    for(int i=0;i<=1e5+5;i++)
        sum[i]=cnt[i]=0;
    for(int i=1;i<=n;i++)
        cin>>date[i];
    for(int i=1;i<=m;i++){
        cin>>x0>>y0>>x1>>y1;
        qr[i]=qs(x0,x1,y0,y1,i);
    }
    sort(qr+1,qr+m+1);
    int l=qr[1].l,r=qr[1].r;
    for(int i=l;i<=r;i++)
        move(i,1);
    ans[qr[1].num]=calc(qr[1].yr)-calc(qr[1].yl-1);
    // cout<<l<<' '<<r<<endl;
    for(int i=2;i<=m;i++){
        while(l>qr[i].l)move(--l,1);
        while(r<qr[i].r)move(++r,1);
        while(l<qr[i].l)move(l++,0);
        while(r>qr[i].r)move(r--,0);
        ans[qr[i].num]=calc(qr[i].yr)-calc(qr[i].yl-1);
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
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
cin>>t;
// read(t);
while (t--)
{
work();
}
// flush();
return 0;
}