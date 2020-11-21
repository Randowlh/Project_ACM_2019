#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod= 998244353;
const int _G=3;
const int maxn=2010000;
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
ll powmod(ll a,ll t=mod-2){
  ll ans=1;
  while(t){
    if(t&1)ans=ans*a%mod;
    a=a*a%mod;t>>=1;
  }return ans;
}
const int invG=powmod(_G);
int tr[maxn<<1],tf;
void tpre(int n){
  if (tf==n)return;
  tf=n;
  for(int i=0;i<n;i++)
    tr[i]=(tr[i>>1]>>1)|((i&1)?n>>1:0);
}
ull f[maxn<<1],w[maxn<<1];
void NTT(ll *g,bool op,int n)
{
  f[0]=1;w[0]=1;
  tpre(n);
  for (int i=0;i<n;i++)f[i]=(((ll)mod<<5)+g[tr[i]])%mod;
  for(int l=1;l<n;l<<=1){
    ull tG=powmod(op?_G:invG,(mod-1)/(l+l));
    for (int i=1;i<l;i++)w[i]=w[i-1]*tG%mod;
    for(int k=0;k<n;k+=l+l)
      for(int p=0;p<l;p++){
        ll tt=w[p]*f[k|l|p]%mod;
        f[k|l|p]=f[k|p]+mod-tt;
        f[k|p]+=tt;
      }      
    if (l==(1<<10))
      for (int i=0;i<n;i++)f[i]%=mod;
  }if (!op){
    ull invn=powmod(n);
    for(int i=0;i<n;++i)
      g[i]=f[i]%mod*invn%mod;
  }else for(int i=0;i<n;++i)g[i]=f[i]%mod;
}
void px(ll *f,ll *g,int n)
{for(int i=0;i<n;++i)f[i]=1ll*f[i]*g[i]%mod;}
ll _g1[maxn<<1];
#define sav _g1
void times(ll *f,ll *g,int len,int lim)
{
  int n=1;
  for(n=1;n<len+len;n<<=1)
    ;
  cpy(sav,g,n);
  for(int i=len;i<n;i++)sav[i]=0;
  NTT(f,1,n);NTT(sav,1,n);
  px(f,sav,n);NTT(f,0,n);
  for(int i=lim;i<n;++i)f[i]=0;
  clr(sav,n);
}
ll a[4100000],b[4100000];
int main(){
    //freopen("in.txt", "r", stdin);
    int n,m;
    rd(n),rd(m);
    for(int i=0;i<=n;i++)
        rd(a[i]);
    for(int i=0;i<=m;i++)
        rd(b[i]);
    times(a,b,n+m,n+m+100);
    for(int i=0;i<=n+m;i++)      
        printf("%lld ",a[i]);
}
