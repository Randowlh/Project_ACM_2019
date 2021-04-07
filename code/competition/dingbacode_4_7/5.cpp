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
int dp[20][2][10][10][2],disg[20];
int dfs(int pos, int staus, int flag, int mod,int p,int kk)
{
    // cout<<"pos="<<pos<<' '<<staus<<' '<<mod<<endl;
    // cout<<"pre="<<pre<<endl;
    if (pos == 0)
        return ((staus == 1)^kk) && ((mod ==0)^kk);
    if (flag && dp[pos][staus][mod][p][kk] != -1)
        return dp[pos][staus][mod][p][kk];
    int num = flag ? 9 : disg[pos];
    int ans = 0;
    for (int i = 0; i <= num; i++)
    {
        if (staus == 1 || ( i == p))
            ans += dfs(pos - 1, 1, flag || i < num, (mod*10  + i) % p,p,kk);
        else
            ans += dfs(pos - 1, 0, flag || i < num, (mod*10  + i) % p,p,kk);
    }
    if (flag)
        dp[pos][staus][mod][p][kk] = ans;
    return ans;
}
inline int calc(int val,int kk,int p){
    memset(disg,0,sizeof(disg));
    int cnt = 1;
    while (val)
    {
        disg[cnt] = val % 10;
        val /= 10;
        cnt++;
    }
    cnt--;
    // for(int i=1;i<=cnt;i++)
        // cout<<"disg"<<disg[i]<<' '<<i<<endl;
    // cout<<"asdasdsa"<<endl;
    int aa= dfs(cnt,0,0,0,p,kk);
    // cout<<"ans="<<aa<<endl;
    return aa;
}
void work()
{
    memset(dp, -1, sizeof(dp));
    int n;
    rd(n);
    int l,r,p;
    for(int i=1;i<=n;i++){
        rd(l),rd(r),rd(p);
        l--;
        int ta=calc(l,0,p)+calc(l,1,p);
         int tb=calc(r,0,p)+calc(r,1,p);
        // cout<<ta<<' '<<tb<<endl;
        // int tb=0;
        ta=l-ta;
        tb=r-tb;
        wt(tb-ta),pt('\n');
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
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