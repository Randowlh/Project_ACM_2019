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
const int maxn = 310000;
string mp[maxn];
int dp[maxn];
int ch[maxn];
void work()
{
   int n,m;
   cin>>n>>m;
//    cout<<"n="<<n<<' '<<m<<endl;
   for(int i=0;i<n;i++)
      cin>>mp[i];
   dp[0]=dp[1]=0;
   dp[2]=1;
   ch[0]=1;
   for(int i=1;i<=maxn-10;i++)
      ch[i]=ch[i-1]*2%mod;
   for(int i=3;i<=max(n,m);i++){
      dp[i]=dp[i-1]+2*dp[i-2]%mod+ch[i-2];
      dp[i]%=mod;
   }
   int tot=0;
   for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
         tot+=(mp[i][j]=='o');
//    cout<<"tot="<<tot<<endl;
   int ans=0;
   for(int i=0;i<n;i++){
      int cnt=0;
      for(int j=0;j<m;j++)
         if(mp[i][j]=='*'){
            ans+=dp[cnt]*(ch[tot-cnt])%mod;
            cnt=0;
         }else cnt++;
      ans+=dp[cnt]*(ch[tot-cnt])%mod;
      cnt=0;
   }
   for(int j=0;j<m;j++){
      int cnt=0;
      for(int i=0;i<n;i++)
            if(mp[i][j]=='*'){
               ans+=dp[cnt]*(ch[tot-cnt])%mod;
            //    cout<<ch[tot-cnt]<<endl;
               // ans%=mod;
               cnt=0;
            }else cnt++;
      ans+=dp[cnt]*(ch[tot-cnt])%mod;
            cnt=0;

   }
   cout<<ans%mod<<endl;
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
// cin>>t;
while (t--)
{
work();
}
return 0;
}