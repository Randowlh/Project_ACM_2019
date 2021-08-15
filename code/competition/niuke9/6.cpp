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
// #define mul(a,b,mod) (__int128)(a)*(b)%(mod) 
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
const ll llinf = 4223372036854775851;
const ll mod = (0 ? 1000000007 : 998244353);
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}

inline int pow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn =2010000;
typedef vector<int> poly;

const int Ntt_Lim = 5e6+6;
	int rev[Ntt_Lim],_w[Ntt_Lim];
	const int G_mod = 3;
	inline void _w_init(){
		for(int step=1;step*2<=Ntt_Lim;step<<=1){
			int wn = pow(G_mod, (mod-1)/(step<<1));
			for(int j=step,w=1;j<step<<1;j++,w=mul(w,wn)){
				_w[j]=w;
			}
		}
	}
	inline void dft(int *f,int len,int type){
		int l=0;while(1<<l<len)++l;
		for(int i=0;i<len;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<len;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
		for(int step=1;step<len;step<<=1){
			for(int i=0;i<len;i+=step<<1)for(int x,y,j=0;j<step;j++){
				x=f[i+j],y=mul(_w[j+step],f[i+j+step]);
				f[i+j]=add(x,y),f[i+j+step]=sub(x,y);
			}
		}
		if(type==1)return;
		int inv=pow(len,mod-2);reverse(f+1,f+len);
		for(int i=0;i<len;i++)f[i]=mul(f[i],inv);
	}
	poly ntt(poly a,poly b,int n,int m){
		int l=1;while(l<n+m-1)l<<=1;
		a.resize(l),b.resize(l);dft(&a[0],l,1),dft(&b[0],l,1);
		for(int i=0;i<l;i++)a[i]=mul(a[i],b[i]);
		dft(&a[0],l,-1);a.resize(n+m-1);
		return a;
	}
	poly ntt(poly a,poly b){return ntt(a,b,a.size(),b.size());}
vector<int>date(maxn,0);
int fac[maxn], ifac[maxn];
inline void init(int n = 2e6){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=pow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
void work()
{
    init();
    int n;
    cin>>n;
    int tmp;
    int ans=1;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        date[tmp+1]++;
        ans=ans*(tmp+1)%mod;
    }
    vector<int> rvs=date;
    reverse(rvs.begin(),rvs.end());
    vector<int> aa=ntt(date,rvs);
    for(int i=1;i<=n;i++)ans = ans*ifac[i]%mod;
    for(int i=1;i<=2000000;i++)
        ans=ans*pow(i,date[2000000+i])%mod;
    cout<<ans<<endll;
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
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}