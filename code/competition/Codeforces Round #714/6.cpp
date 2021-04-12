#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <immintrin.h>
#include <emmintrin.h>
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#pragma GCC optimize(2)
#include<bits/stdc++.h> 
#define ll long long
#define I128 __int128
#define ld long double
#define PB push_back
using namespace std;
const int MAXN=4e6+666,mod=998244353;//
const ll INF=0x7ffffffffffffff,MOD=1e9+7;
const double PI=acos(-1);
typedef pair<int,int> pii;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
template<class T>inline T ksm(T x,T y){T ans=1;while(y>0){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}
template<class T>inline T GCD(T x,T y){if(x==1||y==1)return 1;if(y>x)swap(x,y);while(x%y!=0){x=x%y;swap(x,y);}return y;}
//I128 ksm(I128 x,I128 y){I128 ans=1;while(y>0){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}
//I128 GCD(I128 x,I128 y){if(x==1||y==1)return 1;if(y>x)swap(x,y);while(x%y!=0){x=x%y;swap(x,y);}return y;}
struct T{ ll val,p; }x[MAXN];
ll vis[MAXN],val[MAXN];
int cmp(T t1,T t2){ return t1.val<t2.val; }
int main()
{
	ll m,n,i,j,k,t,a,b; rd(t);
	while(t--)
	{
		rd(n); rd(m);
		ll ans=0,cnt=0;
		for(i=1;i<=n;i++) rd(val[i]),x[i].val=val[i],vis[i]=0,x[i].p=i;
		sort(x+1,x+n+1,cmp);
		for(i=1;i<=n;i++)
		{
			if(x[i].val>=m) break;
			if(vis[x[i].p]) continue;
			int l=x[i].,r=x[i].p,p=x[i].p;
			while(l>1&&!vis[l-1]&&val[l-1]%val[p]==0) vis[l]=1,l--,ans+=val[p],cnt++;
			while(r<n&&!vis[r+1]&&val[r+1]%val[p]==0) vis[r]=1,r++,ans+=val[p],cnt++;
		}
		ans+=(n-1-cnt)*m;
		cout<<ans<<"\n";
	}
}
