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
const ll llinf = 4223372036854775851;
const ll mod = (0 ? 1000000007 : 998244353);
ll pow(ll a,ll b,ll md=mod) {ll res=1;a%=md; assert(b>=0); for(;b;b>>=1){if(b&1)res=mul(res,a,md);a=mul(a,a,md);}return res;}
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
// #define repeat(i,x,y) for(int i=(x);i<(y);++i)
struct MTT{
	static const int N=1<<20;
	struct cp{
		long double a,b;
		cp(){a=0,b=0;}
		cp(const long double &a,const long double &b):a(a),b(b){}
		cp operator+(const cp &t)const{return cp(a+t.a,b+t.b);}
		cp operator-(const cp &t)const{return cp(a-t.a,b-t.b);}
		cp operator*(const cp &t)const{return cp(a*t.a-b*t.b,a*t.b+b*t.a);}
		cp conj()const{return cp(a,-b);}
	};
	cp wn(int n,int f){
		static const long double pi=acos(-1.0);
		return cp(cos(pi/n),f*sin(pi/n));
	}
	int g[N];
	void dft(cp a[],int n,int f){
		for(int i=0;i<n;i++)if(i>g[i])swap(a[i],a[g[i]]);
		for(int i=1;i<n;i<<=1){
			cp w=wn(i,f);
			for(int j=0;j<n;j+=i<<1){
				cp e(1,0);
				for(int k=0;k<i;e=e*w,k++){
					cp x=a[j+k],y=a[j+k+i]*e;
					a[j+k]=x+y,a[j+k+i]=x-y;
				}
			}
		}
		if(f==-1){
			cp Inv(1.0/n,0);
			for(int i=0;i<n;i++)a[i]=a[i]*Inv;
		}
	}
	cp a[N],b[N],Aa[N],Ab[N],Ba[N],Bb[N];
	vector<ll> conv_mod(const vector<ll> &u,const vector<ll> &v,ll mod){ // 任意模数fft
		const int n=(int)u.size()-1,m=(int)v.size()-1,M=sqrt(mod)+1;
		const int k=32-__builtin_clz(n+m+1),s=1<<k;
		g[0]=0; for(int i=1;i<s;i++)g[i]=(g[i/2]/2)|((i&1)<<(k-1));
		for(int i=0;i<s;i++){
			a[i]=i<=n?cp(u[i]%mod%M,u[i]%mod/M):cp();
			b[i]=i<=m?cp(v[i]%mod%M,v[i]%mod/M):cp();
		}
		dft(a,s,1); dft(b,s,1);
		for(int i=0;i<s;i++){
			int j=(s-i)%s;
			cp t1=(a[i]+a[j].conj())*cp(0.5,0);
			cp t2=(a[i]-a[j].conj())*cp(0,-0.5);
			cp t3=(b[i]+b[j].conj())*cp(0.5,0);
			cp t4=(b[i]-b[j].conj())*cp(0,-0.5);
			Aa[i]=t1*t3,Ab[i]=t1*t4,Ba[i]=t2*t3,Bb[i]=t2*t4;
		}
		for(int i=0;i<s;i++){
			a[i]=Aa[i]+Ab[i]*cp(0,1);
			b[i]=Ba[i]+Bb[i]*cp(0,1);
		}
		dft(a,s,-1); dft(b,s,-1);
		vector<ll> ans;
		for(int i=0;i<n+m+1;i++){
			ll t1=llround(a[i].a)%mod;
			ll t2=llround(a[i].b)%mod;
			ll t3=llround(b[i].a)%mod;
			ll t4=llround(b[i].b)%mod;
			ans.push_back((t1+(t2+t3)*M%mod+t4*M*M)%mod);
		}
		return ans;
	}
}mtt;
void work()
{
    int n,m,p;
    cin>>n>>m>>p;
    vector<int> a,b;
    int tmp;
    for(int i=0;i<=n;i++)
        cin>>tmp,a.push_back(tmp);
    for(int i=0;i<=m;i++)
        cin>>tmp,b.push_back(tmp);
    vector<int> ans=mtt.conv_mod(a,b,p);
    for(auto i:ans)
        cout<<i<<' ';
    cout<<endl;
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
    // cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}