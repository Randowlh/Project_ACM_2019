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
typedef unsigned long long ull;
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 110000;
const int b = 131;
ull h[maxn], pw[maxn]; // h[k]存储字符串前k个字母的哈希值, pw[k]存储 b^k mod 2^64
//这里的模数M取的就是ull的上限2^64
int eng[100];
string str;
// int n,k;
void init(int n){//初始化 
    pw[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        h[i] = h[i-1]*b + str[i];//做每个前缀的哈希值 
        pw[i] = pw[i-1]*b;//预处理b^k的值 
    }
}
ull get(int l, int r) {
    return h[r] - h[l-1]*pw[r-l+1];
}
int n,k;
string tmp;
int pre[maxn];
set<unsigned int> s;
bool ck(int x){
    s.clear();
    int l=1,r=0;
    int tot=0;
    for(int i=1;i<=n;i++){
        cout<<"x="<<x<<endl;
        // while(pre[r+1]-pre[i-1]<=x)
        //     r++;
        // cout<<i<<' '<<r<<endl;
        // int bg=i,ed=r;
        // while(bg^ed){
        //     int mid=(bg+ed)>>1;
        //     if(s.count(get(i,mid)))
        //         bg=mid+1;
        //     else ed=mid;
        // }
        // for(int j=bg;j<=r;j++)
        //     s.insert(get(i,j));
    }
    return s.size()>k;
}
void work()
{
    cin>>n>>k;
    cin>>str;
    str=" "+str;
    for(int i=0;i<26;i++)
        cin>>eng[i];
    init(str.size());
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+eng[str[i]-'a'];
    int l=0,r=pre[n];
    while(l^r){
        int mid=(l+r)>>1;
        if(ck(mid))
            r=mid;
        else l=mid+1;
    }
    cout<<l<<endll;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   //freopen("in.txt","r",stdin);
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