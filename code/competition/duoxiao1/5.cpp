#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
// #include <bits/extc++.h>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
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
#define INF 0x7fffffff
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
const int maxn = 1LL<<21;
int ma[maxn],mi[maxn];
int ma2[maxn],mi2[maxn];
int a[maxn],b[maxn];
int res[maxn];
void work()
{
    int n;
    rd(n);
    for(int i=0;i<n;i++)
        rd(a[i]);
    for(int i=0;i<n;i++)
        rd(b[i]);
    for(int i=0;i<n;i++){
        ma[i]=a[i],mi[i]=a[i];
        ma2[i]=b[i],mi2[i]=b[i];
    }
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=20;j++){
            if(i&(1LL<<j)){
                int to=i-(1LL<<j);
                MAX(ma[to],ma[i]);
                MIN(mi[to],mi[i]);
                MAX(ma2[to],ma2[i]);
                MIN(mi2[to],mi2[i]);
            }
        }
    }
    int ans=0;
    res[n] = -llinf;
    for(int i=n-1;i>=0;i--){
        res[i] = max(max(ma[i]*ma2[i],mi[i]*mi2[i]),max(ma[i]*mi2[i],mi[i]*ma2[i]));
        res[i] = max(res[i+1],res[i]);
        ans = ans+(res[i]%mod);
        ans%=mod;
        ans+=mod;
        ans%=mod;
    }
    wt(ans),pt('\n');
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
// cin>>t;
rd(t);
while (t--)
{
work();
}
return 0;
}