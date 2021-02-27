#include <bits/stdc++.h>
#include <thread>
using namespace std;
#pragma optimize(2)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
template<class T>
void wt(T x){
   if(x < 0) putchar('-'), x = -x;
   if(x >= 10) wt(x / 10);
   putchar('0' + x % 10);
}
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
const int maxn = 510000;
double t[510000];
int x,y;
double v1,v2;
double calc(int pos,int tog){
   double ans=pos/v1;
   double dis=sqrt((x-pos)*(x-pos)+tog*tog);
   double vv=log(1+t[pos]*tog);
   ans+=dis/vv;
   ans+=(y-tog)/v2;
   return ans;
}
double ans;
void getans(int ll,int rr){
for(int i=ll;i<=rr;i++){
   double l=0,r=y;
   while((r-l)>=10){
      int lm=l+(r-l)/3;
      int rm=r-(r-l+2)/3;
      if(calc(i,lm)>=calc(i,rm))
         l=lm;
      else r=rm;
   }
   for(int j=l;j<=r;j++)
      MIN(ans,calc(i,j));
   }
}
void work()
{
   rd(x),rd(y);
   scanf("%lf%lf",&v1,&v2);
   int a,b,c,p;
   rd(a),rd(b),rd(c),rd(p);
   for (int i=0; i<=x; i++){
      t[i]=(double)a/c;
      a=(long long)a*b%p;
   }
   ans=x/v1+y/v2;
   int mid=(0+x)>>1;
   int mid1=(0+mid)>>1;
   int mid2=(mid+1+x)>>1;
   thread t1(calc,0,mid1);
   thread t2(calc,mid1+1,mid);
   thread t3(calc,mid+1,mid2);
   thread t4(calc,mid2+1,x);
   t1.join();
   t2.join();
   t3.join();
   t4.join();
   printf("%.4lf\n",ans);
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
//std::ios::sync_with_stdio(false);
//cin.tie(NULL);
int t = 1;
cin>>t;
//cin>>t;
while (t--)
{
work();
}
return 0;
}