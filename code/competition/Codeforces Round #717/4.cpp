#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
#define pii(a,b) pair<a,b>
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
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 110000;
int ss[maxn];
int gcd(int a, int b){ return b ? gcd(b, a % b): a;}
int aft[25][maxn];
int date[maxn];
vector<int> primes;
bool is_prime[111100];
void euler()
{
   is_prime[1] = 1;
   for (int i = 2; i < maxn; i++)
   {
      if (!is_prime[i])
      primes.push_back(i);
      for (int j = 0; j < primes.size() && i * primes[j] < maxn; j++)
      {
         is_prime[i * primes[j]] = 1;
         if ((i % primes[j]) == 0)
            break;
      }
   }
}
void work()
{
   euler(); 
   int n,q;
   cin>>n>>q;
   for(int i=0;i<25;i++)
      aft[i][n+1]=n+1;
   for(int i=1;i<=n;i++)
      cin>>date[i],aft[0][i]=n+1;
   for(int i=n;i>=1;i--){
      int tt=date[i];
      aft[0][i]=aft[0][i+1];
      for(int j=0;j<primes.size()&&primes[j]*primes[j]<=tt;j++){
         if(tt%primes[j]==0){
            if(ss[primes[j]])
               MIN(aft[0][i],ss[primes[j]]);
            ss[primes[j]]=i;  
            while(tt%primes[j]==0)
               tt/=primes[j];
         }
      }
      if(tt!=1){
         if(ss[tt])
            MIN(aft[0][i],ss[tt]);
         ss[tt]=i;
      }
   }
   for(int i=1;i<=23;i++) 
      for(int j=1;j<=n;j++)
         aft[i][j]=aft[i-1][aft[i-1][j]];
   // cout<<":asdsaasddsa"<<endl;
   // for(int j=0;j<=4;j++){
   // for(int i=1;i<=n;i++)
   //    cout<<aft[j][i]<<' ';
   // cout<<endl;
   // }
   
   int l,r;
   for(int _=0;_<q;_++){
      cin>>l>>r;
      int ans=0;
      int now=l;
      while(1){
         // cout<<"dasassadsda"<<endl;
         int ff=0;
         for(int i=23;i>=0;i--)
            if(aft[i][now]<=r){
               now=aft[i][now];
               ff=1;
               ans+=(1<<i);
               break;
            }
         if(!ff){
            ans++;
            break;
         }
      }
      cout<<ans<<endl;
   }
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