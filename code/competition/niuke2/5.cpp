#include <bits/stdc++.h>
//#include <bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
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
#define pow powmod
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
ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 81000;
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
// int lk[maxn];
int date[maxn];
vector<int> mp[maxn];
int C[maxn][40];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
void init(){
    for(int i=0;i<35;i++){
        C[0][i]=0;
        C[i][0]=1;
    }
    for(int i=1; i<=maxn; ++i)
        for(int j=1; j<=35; ++j)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
}
void work()
{
    int n,k;
    cin>>n>>k>>mod;
    // cout<<"dadasddsds"<<endl;
    init();
    for(int i=1;i<=n;i++)
        cin>>date[i];
    for(int i=0;i<=maxn;i++)
        mp[i].clear();
    // cout<<"asdasdasd"<<endl;
    for(int i=1;i<=n;i++){
        int tmp=date[i];
        for(int j=2;j*j<=tmp;j++){
            if(tmp%j==0){
                int cnt=0;
                while(tmp%j==0){
                    cnt++;
                    tmp/=j;
                }
                // cout<<date[i]<<' '<<j<<' '<<cnt<<endl;
                mp[j].push_back(cnt);
            }
        }
        if(tmp!=1)
            mp[tmp].push_back(1);
    }
    // cout<<"asdasddas"<<endl;
    for(int i=0;i<maxn;i++)
        sort(mp[i].begin(), mp[i].end());
    // cout<<"dasadasd"<<endl;
    int ans=1;
    for(int i=0;i<maxn;i++){
        // int ff=0;
        for(int j=0;j<(int)mp[i].size()-k+1;j++){
            // ff=1;
            // cout<<mp[i][j]<<' ';
            ans=ans*powmod(powmod(i,mp[i][j]),C[mp[i].size()-j-1][k-1])%mod; 
        }
        // if(ff)
        // cout<<" i="<<i <<endl;
    }
    cout<<ans<<endl;
}
signed main()
{
    euler();
    // for(int i=0;i<primes.size();i++){
    //     lk[primes[i]]=i;
    // }
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif

std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}