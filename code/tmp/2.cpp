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
const int maxn = 510000;
int dp[30][200];
vector<int> dd[30][200];
int w[30],v[30];
void work()
{
    for(int i=1;i<=24;i++){
        cin>>w[i];
    }
    for(int i=1;i<=24;i++)  
        cin>>v[i];
    memset(dp, 63, sizeof dp);
    dp[0][0]=0;
    for(int i=1;i<=24;i++){
        for(int j=1;j<=24;j++)
            for(int k=w[i];k<=25;k++){
              
                if(dp[j][k]>dp[j-1][k-w[i]]+v[i]){
                     cout<<i<<' '<<j<<' '<<k<<' '<<dp[j-1][k-w[i]]<<endl;
                    dp[j][k]=dp[j-1][k-w[i]]+v[i];
                    dd[j][k]=dd[j-1][k-w[i]];
                    dd[j][k].push_back(i);
                }
            }
    }
    vector<int> aa;
    int ans=99999999;
    for(int i=12;i<=24;i++){
        for(int j=1;j<=25;j++){
            if(ans>dp[i][j]){
                ans=dp[i][j];
                aa=dd[i][j];
            }
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<aa.size();i++){
        cout<<aa[i]<<' ';
    }
    cout<<endl;
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