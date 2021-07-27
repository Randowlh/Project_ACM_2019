#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
string cst="0123456789ABCDEF";
int seg[maxn<<2][3];
int c[maxn][3];
int dp[maxn];
string biao[300];
struct node{
    int r,g,b;
    node(int a,int b,int c):r(a),g(b),b(c) {}
    node(){}
};
inline void pushup(int pos){
    // for(int i=0;i<3;i++)
    seg[pos][0]=seg[lson(pos)][0]+seg[rson(pos)][0];
    seg[pos][1]=seg[lson(pos)][1]+seg[rson(pos)][1];
    seg[pos][2]=seg[lson(pos)][2]+seg[rson(pos)][2];
}
void build(int pos,int l,int r){
    if(l==r){
        seg[pos][0]=c[l][0]; 
        seg[pos][1]=c[l][1];     
        seg[pos][2]=c[l][2];  
        return;
    }
    int mid=(l+r)>>1;
    build(lson(pos),l,mid);
    build(rson(pos),mid+1,r);
    pushup(pos);
}
node query(int pos,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr){
        return node(seg[pos][0],seg[pos][1],seg[pos][2]);
    }
    int mid=(l+r)>>1;
    node ans(0,0,0);
    if(ql<=mid){
        node tt=query(lson(pos),l,mid,ql,qr);
        ans.b+=tt.b;
        ans.g+=tt.g;
        ans.r+=tt.r;
    }
    if(qr>=mid+1){
        node tt=query(rson(pos),mid+1,r,ql,qr);
        ans.b+=tt.b;
        ans.g+=tt.g;
        ans.r+=tt.r;
    }
    return ans;
}
inline int trans(string er){
    int ans=0;
    if(!isdigit(er[0])){
        ans+=160;
        ans+=16*(er[0]-'A');
    }else{
        ans+=16*(er[0]-'0');
    }
    if(!isdigit(er[1])){
        ans+=10;
        ans+=(er[1]-'A');
    }else{
        ans+=(er[1]-'0');
    }
    return ans;
}
inline string rtans(int t){
    string ans;
    ans.push_back(cst[t/16]);
    ans.push_back(cst[t%16]);
    return ans;
}
void work()
{
    int n,q;
    cin>>n>>q;
    string tmp;
    for(int i=1;i<=n;i++){
        cin>>dp[i]>>tmp;
        if(dp[i]!=1)
            dp[i]=0;
        c[i][0]=trans(tmp.substr(0,2));
        c[i][1]=trans(tmp.substr(2,2));
        c[i][2]=trans(tmp.substr(4,2));
    }
    build(1,1,n);
    int now=0;
    for(int i=1;i<=n;i++){
        if(dp[i])
            now=i;
        dp[i]=now;
    }
    int l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        MAX(l,dp[r]);
        node tt=query(1,1,n,l,r);
        MIN(tt.r,255);
        MIN(tt.g,255);
        MIN(tt.b,255);
        cout<<biao[tt.r]<<biao[tt.g]<<biao[tt.b]<<'\n';
    }
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
    for(int i=0;i<=255;i++)
        biao[i]=rtans(i);
    cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}