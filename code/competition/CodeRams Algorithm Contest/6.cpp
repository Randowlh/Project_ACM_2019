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
int date[410][410],dp[410][410];
int maa[410][410][410];
inline int calc(int x1,int y1,int x2,int y2){
   if(x1>x2||y1>y2) return 0;
   return (dp[x2][y2]+dp[x1-1][y1-1]-dp[x1-1][y2]-dp[x2][y1-1]);
}
void work()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            cin>>date[i][j];
   for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+date[i][j];
   for(int i=1;i<=n;i++)
      for(int j=i;j<=n;j++){
         maa[i][j][n+1]=-inf;
         for(int k=n;k>=1;k--)
            MAX(maa[i][j][k],max(maa[i][j][k+1],calc(i,1,i,k-1)+calc(i,k,j,k)+calc(j,1,j,k-1)));
      }
   int ans=-inf;
   for(int x=1;x<=n;x++)
      for(int y=1;y+2<=n;y++)
         for(int len=2;x+len<=n;len++)
            MAX(ans,maa[x][x+len][y+1]-calc(x,1,x,y-1)-calc(x+len,1,x+len,y-1)+calc(x+1,y,x+len-1,y));
   cout<<ans<<endl;
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}