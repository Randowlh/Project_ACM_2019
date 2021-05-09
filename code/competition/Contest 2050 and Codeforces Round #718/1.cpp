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
int b[][2]={{1,0},{-1,0},{0,1},{0,-1}};
int lk[510][510][4];
int dp[510][510][12];
int n,m,k;
bool ck(int x,int y){
    if(x<=0||x>n)
        return false;
    if(y<=0||y>m)
        return false;
    return true;
}
int dfs(int x,int y,int step){
    if(step==k)
        return 0;
    if(dp[x][y][step]!=-1)
        return dp[x][y][step];
    int aa=llinf;
    for(int i=0;i<4;i++)
        if(ck(x+b[i][0],y+b[i][1]))
            MIN(aa,lk[x][y][i]+dfs(x+b[i][0],y+b[i][1],step+1));
    dp[x][y][step]=aa;
    return aa;
}
void work()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    int tmp;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++){
            cin>>tmp;
            lk[i][j][2]=tmp;
            lk[i][j+1][3]=tmp;
        }
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=m;j++){
            cin>>tmp;
            lk[i][j][0]=tmp;
            lk[i+1][j][1]=tmp;
        }
    if(k%2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cout<<-1<<' ';
            cout<<endl;
        }
        return;
    }
    k>>=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dfs(i,j,0)*2<<' ';
        }
        cout<<endl;
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