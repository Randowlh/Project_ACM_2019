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
int date[25][51000];
int cnt[25];
int inv(int a, int p)
{
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
void work()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    int tmp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>date[i][j];
    for(int j=1;j<=m;j++){
        for(int i=0;i<=n+2;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            cnt[date[i][j]]++;
        for(int i=n;i>=1;i--)
            cnt[i]=cnt[i+1]+cnt[i];
        // cout<<"j="<<j<<endl; 
        // for(int i=1;i<=n;i++){
        //     cout<<cnt[i]<<' ';
        // }  
        // cout<<endl;
        int p=1;
        for(int i=1;i<=n;i++)
            p=p*(cnt[n-i+2]-i+1)%mod*inv(n-i+1,mod)%mod;
        ans+=(1-p+mod)%mod;
        ans%=mod;
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