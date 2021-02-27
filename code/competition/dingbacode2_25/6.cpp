#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
double t[110000];
double v1,v2;
int x,y;
int a,b,c,p;
double calc(int pos,int tog){
   double ans=pos/v1;
   double dis=sqrt((x-pos)*(x-pos)+tog*tog);
   double vv=log(1+t[pos]*tog);
   ans+=dis/vv;
   ans+=(y-tog)/v2;
   return ans;
}
void work()
{
    
    cin>>x>>y;  
    cin>>v1>>v2;
    cin>>a>>b>>c>>p;
     for (int i=0; i<=x; i++){
      t[i]=(double)a/c;
      a=(long long)a*b%p;
    }
    double ans=llinf;
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            double tt=(x-i)*(x-i)+j*j;
            tt=sqrt(tt);
            // MIN(ans,tt/log(1+t[i]*j)+i/v1+(y-j)/v2);
            MIN(ans,calc(i,j));
        }
    }
    printf("%.4lf\n",ans);
 
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
// std::ios::sync_with_stdio(false);
// cin.tie(NULL);
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}