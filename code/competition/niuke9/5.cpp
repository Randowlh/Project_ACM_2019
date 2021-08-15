// #pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define repeat(i,x,y) for(int i=(x);i<(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define mst(a,x) memset(a,x,sizeof(a))
#define endl "\n"
#define fr first
#define sc second
#define debug cout<<"DEBUG\n";
#define OMG(a,n) rep(i,1,n) cout<<a[i]<<" "; cout<<endl;
#define OMG2(a,n,m) rep(i,1,n) {rep(j,1,m) cout<<a[i][j]<<" "; cout<<endl;}
template <typename Type> void RIP(Type x) {cout<<x<<endl;}template <typename Type, typename... Targs>void RIP(Type x, Targs... args) {cout<<x<<" ";RIP(args...);}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll; typedef unsigned long long ull; typedef pair<int,ll>pil; typedef pair<int,int>pii; typedef pair<ll,ll>pll;
const int N=810; const double eps=1e-9;
const int inf=0x3f3f3f3f; const ll INF=0x3f3f3f3f3f3f3f3f;
const int mo=(1?998244353:1000000007); ll mul(ll a,ll b,ll m=mo){return a*b%m;} ll fpow(ll a,ll b,ll m=mo){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
inline ll read(){ll x=0,tag=1; char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')tag=-1;for(; isdigit(c);c=getchar())x=x*10+c-48;return x*tag;}
typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} template<typename T> T sqr(T x){return x*x;}

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
		repeat(i,0,n)if(i>g[i])swap(a[i],a[g[i]]);
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
			repeat(i,0,n)a[i]=a[i]*Inv;
		}
	}

	cp a[N],b[N],Aa[N],Ab[N],Ba[N],Bb[N];
	vector<ll> conv_mod(const vector<ll> &u,const vector<ll> &v,ll mod){ // 任意模数fft
		const int n=(int)u.size()-1,m=(int)v.size()-1,M=sqrt(mod)+1;
		const int k=32-__builtin_clz(n+m+1),s=1<<k;
		g[0]=0; repeat(i,1,s)g[i]=(g[i/2]/2)|((i&1)<<(k-1));
		repeat(i,0,s){
			a[i]=i<=n?cp(u[i]%mod%M,u[i]%mod/M):cp();
			b[i]=i<=m?cp(v[i]%mod%M,v[i]%mod/M):cp();
		}
		dft(a,s,1); dft(b,s,1);
		repeat(i,0,s){
			int j=(s-i)%s;
			cp t1=(a[i]+a[j].conj())*cp(0.5,0);
			cp t2=(a[i]-a[j].conj())*cp(0,-0.5);
			cp t3=(b[i]+b[j].conj())*cp(0.5,0);
			cp t4=(b[i]-b[j].conj())*cp(0,-0.5);
			Aa[i]=t1*t3,Ab[i]=t1*t4,Ba[i]=t2*t3,Bb[i]=t2*t4;
		}
		repeat(i,0,s){
			a[i]=Aa[i]+Ab[i]*cp(0,1);
			b[i]=Ba[i]+Bb[i]*cp(0,1);
		}
		dft(a,s,-1); dft(b,s,-1);
		vector<ll> ans;
		repeat(i,0,n+m+1){
			ll t1=llround(a[i].a)%mod;
			ll t2=llround(a[i].b)%mod;
			ll t3=llround(b[i].a)%mod;
			ll t4=llround(b[i].b)%mod;
			ans.push_back((t1+(t2+t3)*M%mod+t4*M*M)%mod);
		}
		return ans;
	}
}mtt;
void Solve(){
    int n,m,p;
    cin>>n>>m>>p;
    vector<int> a(n+1),b(m+1);
    for(int i=0;i<=n;i++)
        cin>>a[i];
    for(int i=0;i<=m;i++)
        cin>>b[i];
    mtt.conv_mod(a,b,p);

}
int main(){
    // #ifndef ONLINE_JUDGE
        // freopen("in.txt","r",stdin);
        // freopen("out.txt","w",stdout);
    // #endif
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T=1; 
    rep(kase,1,T){
        Solve();
    }
    return 0;
}