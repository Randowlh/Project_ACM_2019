#include <bits/stdc++.h>
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
const int inf = 0x7FFFFFFF;
#define ll __int128 
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
const double eps = 0;
const int maxm= 1;
const int maxn = 1000;
vector<int> primes;
bool is_prime[100100];
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
vector<int> v;
ll powmod(ll a,ll b) {ll res=1; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
void work()
{
    euler();
    int l,r;
    cin>>l>>r;
    l--;
    int cnt1=0,cnt2=0;
    db t1=sqrt(l);
    cnt1+=t1-1;
    db t2=sqrt(r);
    cnt2+=t2-1;
    cout<<cnt1<<' '<<cnt2<<endl;
    cnt1+=v.size()-(lower_bound(v.begin(),v.end(),l,greater<int>())-v.begin());
    cnt2+=v.size()-(lower_bound(v.begin(), v.end(),r,greater<int>())-v.begin());
    if(l==0)
        cnt1=-1;
    cout<<cnt2-cnt1<<endl;
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
cin>>t;
set<ll> s;
for(int i=3;i<=64;i++){
    for(int j=2;j<=1e6+10;j++){
        ll tt=powmod(j,i);
        if(tt>1e18){
            break;
        }
        int aa=sqrt((int)tt);
        // if(aa-(int)aa>eps)

            s.insert(tt);
    }
}
for(auto i=s.begin(); i != s.end(); i++){
    v.push_back(*i);
}
while (t--)
{
work();
}
return 0;
}