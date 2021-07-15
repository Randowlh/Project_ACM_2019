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
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 310000;
int dp[50][maxn];
int tt[50];
int n,m;
int ans[50];
int flag[maxn];
void work()
{
    cin>>n>>m;
    for(int i=n;i>=1;i--){
        dp[0][i]++;
        if(rson(i)<=n){
            for(int j=0;j<40;j++){
                dp[j+1][i]+=dp[j][rson(i)];
                ans[j+1]+=dp[j][rson(i)];
            }
            for(int j=1;j<=40;j++)
                for(int k=0;k<j;k++)
                    ans[j]+=dp[k][i]*dp[j-k-1][lson(i)];
            for(int j=0;j<40;j++)
                dp[j+1][i]+=dp[j][lson(i)];
            continue;    
        }
        if(lson(i)<=n)
            for(int j=0;j<40;j++){
                dp[j+1][i]+=dp[j][lson(i)];
                ans[j+1]+=dp[j][lson(i)];
            }
    }
    char opt;
    int k;
    for(int _=1;_<=m;_++){
        cin>>opt>>k;
        if(opt=='?'){
            int aa=0;
            for(int i=1;i<=k;i++)
                aa+=ans[i];
            cout<<aa<<endl;
            continue;
        }else if(opt=='-'){
            flag[k]=1;
            int now=k/2;
            for(int i=0;i<=40;i++)
                tt[i]=dp[i][k];
            int nxt=(k%2==0?k+1:k-1);
            if(flag[nxt])
                    nxt=0;
            // cout<<"ans="<<endl;
            // for(int i=0;i<=3;i++)
            //     cout<<ans[i]<<' ';
            // cout<<endl;
            while(now){
                for(int i=40;i>=1;i--)
                    tt[i]=tt[i-1];
                tt[0]=0;
                for(int i=1;i<=40;i++){
                    for(int j=1;j<i;j++)
                        ans[i]-=dp[j-1][nxt]*tt[i-j];
                    ans[i]-=dp[0][now]*tt[i];
                }
                for(int i=0;i<=40;i++)
                    dp[i][now]-=tt[i];
                nxt=(now%2==0?now+1:now-1);
                if(flag[nxt])
                    nxt=0;
                // cout<<"ans="<<endl;
                // for(int i=0;i<=3;i++)
                //     cout<<ans[i]<<' ';
                // cout<<endl;
                if(flag[now])
                    break;
                now>>=1;                
            }
        }
    }
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
//cin>>t;
while (t--)
{
work();
}
return 0;
}