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
int gcd(int a, int b){ return b ? gcd(b, a % b) : a;}
struct st_table
{
   int mx[200100][30];
   inline void RMQ(int num)
   {
      for (int j = 1; j < 20; ++j)
         for (int i = 1; i <= num; ++i)
            if (i + (1 << j) - 1 <= num)
               mx[i][j] = gcd(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
   }
   inline int query(int l, int r)
   {
      int k = log2(r - l + 1);
      return gcd(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;
int pre[210000],aft[210000];
// int ddp[210000],df[210000];
int dp[210000];
int date[210000];
vector<pair<int,int>> lk[210000];
void work()
{
    int n,p;
    int ans=0;
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        cin>>date[i],lk[i].clear();
    for(int i=1;i<=n;i++)
        b.mx[i][0]=date[i];
    b.RMQ(n);
    for(int i=1;i<=n;i++){
        int l=1,r=i+1;
        while(l^r){
            int mid=(l+r)>>1;
            if(b.query(mid,i)==date[i])
                r=mid;
            else l=mid+1;
        }
        pre[i]=l;
    }
    for(int i=1;i<=n;i++){
        int l=i,r=n+1;
        while(l^r){
            int mid=(l+r)>>1;
            if(b.query(i,mid)==date[i])
                l=mid+1;
            else r=mid;
        }
        aft[i]=l-1;
    }
    for(int i=1;i<=n;i++)
        dp[i]=llinf;
    for(int i=1;i<=n;i++){
        if(aft[i]>pre[i]){
            lk[aft[i]].push_back(make_pair(pre[i],date[i]));
        }
    }
    dp[n]=0;
    for(int i=n;i>=1;i--){
        MIN(dp[i-1],dp[i]+p);
        for(int j=0;j<lk[i].size();j++){
            int to=lk[i][j].first;
            MIN(dp[to],dp[i]+(i-to)*lk[i][j].second);
        }
    }
    cout<<dp[1]<<endl;
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
while (t--)
{
work();
}
return 0;
}