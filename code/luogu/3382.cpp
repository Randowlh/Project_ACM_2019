#include <bits/stdc++.h>
using namespace std;
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
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
const int maxn = 510000;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-8;
const ll llinf = 4223372036854775807;
db date[110000];
  int n;
double f(double a){
    double ans=0;
    double now=1;
    for(int i=0;i<n;i++){
        ans+=now*date[i];
        now*=a;
    }
    return ans;
}
void work()
{
    db l,r;
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++){
        cin>>date[i];
    }
    reverse(date,date+1+n);
    for(int i=0;i<n;i++){
        date[i]=date[i+1]*(i+1);
    }
    while((r-l)>100){
        int lm=l+(r-l)/3;
        int rm=r-(r-l+2)/3;
        if(f(lm)<=f(rm)) l=lm;
        else r=rm;
    }
    printf("%.5lf\n",l);
}
signed main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
  //  std::ios::sync_with_stdio(false);
   // cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}