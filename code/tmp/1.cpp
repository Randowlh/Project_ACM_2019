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
struct rcd{
    int l,r,num;
    bool operator<(rcd a){
        int mid=(l+r)>>1;
        int dis=min(mid-l,r-mid);
        int amid=(a.l+a.r)>>1;
        int adis=min(amid-a.l,r-amid);
        if(dis==adis)
            return l<a.l;
        else return dis<adis;
    }
    rcd(int a,int b,int c):l(a),r(b),num(c){}
};
int cz[100100];
set<int> s;
map<int,int> M;
yx_queue<rcd> q;
int cnt=0;
int n,m,tot;
int getpos(int l,int r){
    int ans=(l+r)>>1;
    MAX(ans,1LL);
    MIN(ans,n);
}
bool hf(rcd a){
    if(a.r<=0||a.l>n)
        return false;

}
void work()
{
    while(scanf("%lld%lld",&n,&m)!=EOF){
        s.insert(-llinf);
        s.insert(llinf);
        int opt;
        for(int i=1;i<=m;i++){
            rd(opt);
            if(opt==1){
                if(!cnt){
                    wt(1),pt('\n');
                    s.insert(1);
                    q.push(rcd(1,llinf,++tot));
                    M[1]=tot;
                }

            }else{

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