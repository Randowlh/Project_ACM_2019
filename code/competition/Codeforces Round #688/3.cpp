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
char mp[2010][2010];
pair<int,int> xm[100],ym[100];
pair<int,int> x[20][2010],y[20][2010];
void work()
{
    int  n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<10;j++){
            y[j][i].first=x[j][i].first=n;
            y[j][i].second=x[j][i].second=1;
        }
    for(int j=0;j<=10;j++){
        xm[j].first=ym[j].first=n;
        xm[j].second=ym[j].second=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
            int now=mp[i][j]-'0';
            MAX(xm[now].second,i);
            MIN(xm[now].first,i);
            MAX(ym[now].second,j);
            MIN(ym[now].first,j);
            MIN(x[now][i].first,j);
            MAX(x[now][i].second,j);
            MIN(y[now][j].first,i);
            MAX(y[now][j].second,i);
        }
    // for(int i=1;i<=n;i++)
    //     cout<<y[2][i].first<<" "<<y[2][i].second<<endl;
    // cout<<xm[2].first<<" "<<xm[2].second<<endl;
    // cout<<ym[2].first<<" "<<ym[2].second<<endl;
    for(int i=0;i<=9;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            // if(i==2)
            // cout<<"n="<<n<<endl;
            //     cout<<"i="<<i<<' '<<j<<' '<<x[i][j].first<<' '<<x[i][j].second<<' '<<y[i][j].first<<' '<<y[i][j].second<<endl;
            MAX(ans,max(j-1,n-j)*(x[i][j].second-x[i][j].first));
            // cout<<ans<<endl;
            MAX(ans,max(j-1,n-j)*(y[i][j].second-y[i][j].first));
            // cout<<ans<<endl;
            MAX(ans,(n-x[i][j].first)*max(j-xm[i].first,xm[i].second-j));
            MAX(ans,(x[i][j].second-1)*max(j-xm[i].first,xm[i].second-j));
             MAX(ans,(n-y[i][j].first)*max(j-ym[i].first,ym[i].second-j));
            MAX(ans,(y[i][j].second-1)*max(j-ym[i].first,ym[i].second-j));
            // cout<<ans<<endl;
        }
    cout<<ans<<' ';
    }
    cout<<endl;
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