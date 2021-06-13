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
const ll mod = (1 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 11000;
int n,m;
// int pre[maxn+100];
int dp[2010][2010];
int pp[2010][2010];
int C[4010][4010];
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline int niyuan(int x, int mod) { return powmod(x, mod - 2); }
void init()
{
int i,j;
for(i=0; i<=4000; ++i)
{
C[0][i] = 0;
C[i][0] = 1;
}
for(i=1; i<=4000; ++i)
{
for(j=1; j<=4000; ++j)
C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
}
}

inline int CC(int n, int m)
{
return C[n][m];
}
void work()
{
    cin>>n>>m;
    swap(n,m);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
           pp[i][j]=dp[i][j]=CC(i+j-1,i);
    }
    for(int j=0;j<=m;j++)
        pp[0][j]=j+1,dp[0][j]=1;
    for(int i=1;i<=n;i++)
        pp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pp[i][j]=(pp[i][j]+pp[i-1][j]+pp[i][j-1]-pp[i-1][j-1])%mod;
            // cout<<pp[i][j]<<' ';
        }
        // cout<<endl;
    }
    // cout<<"dp"<<endl;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++)
    //         cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }
    // cout<<"pp"<<endl;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++)
    //         cout<<pp[i][j]<<' ';
    //     cout<<endl;
    // }
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int dis=(dp[i][j]*(pp[n][m-j]-pp[i][m-j]-pp[n][m-j-1]+pp[i][m-j-1]))%mod;
            // cout<<dis<<' ';
            ans+=dis;
            ans%=mod;
        }
        // cout<<endl;
    }
    cout<<ans+1<<endl;
}
signed main()
{
    init();
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}