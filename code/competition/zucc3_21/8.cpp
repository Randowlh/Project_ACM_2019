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
int n,m,k;
int date[310][310];
int pre[310][310];
int dp[1100][310][2];
void work()
{
    rd(n),rd(m),rd(k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            rd(date[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            pre[i][j]=pre[i][j-1]+date[i][j];
        }
    memset(dp,0,sizeof(dp));
    int tot=0;
    for(int i=1;i<=m;i++){
        dp[k-i][i][0]=pre[n][i];
        // cout<<dp[k-i][i][0]<<' '<<k-i<<' '<<i<<endl;
    }
    for(int i=n-1;i>=1;i--){
        // cout<<"dsadasd"<<endl;
        for(int j=0;j<=k;j++)
            for(int s=1;s<=m;s++)
                if(j-s>=0)
                    MAX(dp[j-s][s][1],dp[j][s][0]+pre[i][s]);
        for(int s=1;s<m;s++)
            for(int j=1;j<=k;j++)
                if(dp[j][s][1])
                    MAX(dp[j-1][s+1][1],dp[j][s][1]+date[i][s+1]);
        for(int s=0;s<=k;s++)
            for(int j=1;j<=m;j++){
                dp[s][j][0]=dp[s][j][1];
                dp[s][j][1]=0;
                // cout<<dp[s][j][0]<<' '<<s<<' '<<j<<endl;
            }
    }
    int ans=0;
    for(int i=0;i<=k;i++)
        for(int j=1;j<=m;j++)
            MAX(ans,dp[i][j][0]);
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