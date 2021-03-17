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
const int llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
int t[3100],d[3100];
int pret[3100];
pair<int,int> dp[3100][3100][2];
int n,m;
int ans;
int rod;
int dfs(int l,int r,int pos,int zl){
    int t=((l+1)==pos);
    if(dp[l][r][t].second==rod)
        return dp[l][r][t].first;
    if((l<=0||d[l]>zl)&&(r>n||d[r]>zl)){
        return 0;
    }
    int ans=llinf;
    if(l>=0&&d[l]<=zl)
        MIN(ans,pret[pos-1]-pret[l-1]+dfs(l-1,r,l,zl+d[l]));
    if(r<=n&&d[r]<=zl)
        MIN(ans,pret[r]-pret[pos]+dfs(l,r+1,r,zl+d[r]));
    dp[l][r][t]=make_pair(ans,rod);
    if(r-1==pos)dp[l][r][0]=make_pair(ans,rod);
    return ans;
}
void work()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
        cin>>t[i];
    d[0]=d[n+1]=llinf;
    int zl,x;
    for(int i=1;i<=m;i++){
        rod=i;
        cin>>x>>zl;
        int tmp=t[x];
        t[x]=0;
        for(int j=1;j<=n;j++)
            pret[j]=pret[j-1]+t[j];
        int ans=dfs(x-1,x+1,x,zl);
        cout<<ans<<endl;
        t[x]=tmp;
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
// std::ios::sync_with_stdio(false);
// cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}