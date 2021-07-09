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
const int maxn = 510000;
long double dfs(ld c,ld m,ld p,ld v){
    long double ans=p;
    // if(c>eps){
    //     if(c<v){
    //         if(m>eps) ret+=c*(dfs(0,0.5*c+m,0.5*c+p,v)+1);
    //         else ret+=c*2.0;
    //     }
    //     else{
    //         if(m>eps) ret+=c*(dfs(c-v,0.5*v+m,0.5*v+p,v)+1);
    //         else ret+=c*(dfs(c-v,0,v+p,v)+1);
    //     }
    // }
    // swap(c,m);
    // if(c>eps){
    //     if(c<v){
    //         if(m>eps) ret+=c*(dfs(0,0.5*c+m,0.5*c+p,v)+1);
    //         else ret+=c*2.0;
    //     }
    //     else{
    //         if(m>eps) ret+=c*(dfs(c-v,0.5*v+m,0.5*v+p,v)+1);
    //         else ret+=c*(dfs(c-v,0,v+p,v)+1);
    //     }
    // }
    if(c>0){
        ans+=c;
        if(m>eps){
            if(c>v) ans+=c*dfs(c-v,m+v/2,p+v/2,v);
            else ans+=c*dfs(-1,m+c/2,p+c/2,v);    
        }else{
            if(c>v) ans+=c*dfs(c-v,-1,p+v,v);
            else ans+=c;
        }
    }
    swap(c,m);
    if(c>0){
        ans+=c;
        if(m>eps){
            if(c>v) ans+=c*dfs(c-v,m+v/2,p+v/2,v);
            else ans+=c*dfs(-1,m+c/2,p+c/2,v);    
        }else{
            if(c>v) ans+=c*dfs(c-v,-1,p+v,v);
            else ans+=c;
        }
    }
    return ans;
}
void work()
{
    double c,m,p,v;
    cin>>c>>m>>p>>v;
    printf("%.10Lf\n",dfs(c,m,p,v));
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