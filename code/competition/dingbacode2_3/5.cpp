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
const int maxn = 210;
vector<int> primes;
bool is_prime[1110];
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
int date1[210][1100],date2[210][1100];
void work()
{
    for(int i=1;i<=210;i++)
      primes.push_back(i);
    int n,m;
    int y1,y2;
    cin>>n>>y1;
    int tmp;
    set<int> s;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        s.insert(tmp);
        for(int j=0;j<primes.size();j++){
            date1[j][tmp%(primes[j]*2)]++;
        }
    }
    int aa=0;
    cin>>m>>y2;
    for(int i=1;i<=m;i++){
        cin>>tmp;
        if(s.count(tmp))
        aa++;
        for(int j=0;j<primes.size();j++){
            date2[j][tmp%(primes[j]*2)]++;
        }
    }
    int ans=0;
   //  int ans=max(n,m);
    MAX(ans,2LL*(aa>0));
    for(int j=0;j<primes.size();j++){
        for(int i=0;i<primes[j]*2;i++){
            MAX(ans,date1[j][i]+date2[j][(i+primes[j])%(primes[j]*2)]);
        }
    }
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