#include <bits/stdc++.h>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
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
int dp[1100000][30];
int date[1100000];
int lim[1100000];
int n,m,k;
void calc(int pos){
    if(lim[pos]-lim[pos-1]){
        dp[pos][0]=-1;
        return;
    }
    int l=pos,r=n+1;
    while(l^r){
        int mid=l+r>>1;
        if(date[mid]-date[pos-1]<=k)
            l=mid+1;
        else r=mid;
    }
    dp[pos][0]=l-1;
}
void work()
{
    rd(n),rd(m),rd(k);
    for(int i=1;i<=n;i++){
        rd(date[i]);
        if(date[i]>k)lim[i]=1;
    }
    for(int i=1;i<=n;i++){
        date[i]=date[i-1]+date[i];
        lim[i]=lim[i]+lim[i-1];
    }
    for(int i=1;i<=n;i++)
        calc(i);
    for(int j=1;j<=25;j++){
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]==-1)
                dp[i][j]=-1;
            else
            dp[i][j]=dp[min(n,dp[i][j-1]+1)][j-1];
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }
    int l,r;
    for(int i=1;i<=n;i++){
        rd(l),rd(r);
        if(lim[r]-lim[l-1]){
            printf("Chtholly\n");
            continue;
        }
        int ans=0;
        int now=l;
        while(1){
            int i;
            // cout<<"now="<<now<<' '<<r<<' '<<l<<endl;
            for(i=0;i<=25;i++){
                if(dp[now][i]==r)
                    break;
                if(dp[now][i]>r||dp[now][i]==-1){
                    i--;
                    break;
                }
            }
            if(i==-1){
                ans+=1;
                break;
            }
            if(dp[now][i]==r){
                ans+=1<<(i);
                break;
            }else {ans+=(1<<(i));now=dp[now][i]+1;}
        }
        wt(ans),pt('\n');
    }
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